#include "bang/bang_kernel_without_config.h"
#include "bang/bang_runtime.h"
#include "operators/reduce.h"

namespace infini {
class ReduceMeanCnnl : public BangKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<ReduceMeanObj>(_op);
        auto context = dynamic_cast<const BangRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());

        auto aDim = op->getInputs(0)->getDims();
        auto axes_set = op->getAxes();
        std::vector<int> axes;
        axes.assign(axes_set.begin(), axes_set.end());
        auto bDim = aDim;
        for (auto it : axes) {
            bDim[it] = 1;
        }

        cnnlTensorDescriptor_t inDesc, outDesc;
        checkCnnlError(cnnlCreateTensorDescriptor(&inDesc));
        checkCnnlError(cnnlCreateTensorDescriptor(&outDesc));
        checkCnnlError(cnnlSetTensorDescriptor(inDesc, CNNL_LAYOUT_ARRAY,
                                               CNNL_DTYPE_FLOAT, aDim.size(),
                                               aDim.data()));
        checkCnnlError(cnnlSetTensorDescriptor(outDesc, CNNL_LAYOUT_ARRAY,
                                               CNNL_DTYPE_FLOAT, bDim.size(),
                                               bDim.data()));

        // get reduce descriptor
        cnnlReduceDescriptor_t reduceDesc;
        checkCnnlError(cnnlCreateReduceDescriptor(&reduceDesc));
        checkCnnlError(cnnlSetReduceDescriptor_v2(
            reduceDesc, axes.data(), axes.size(), CNNL_REDUCE_AVG,
            CNNL_DTYPE_FLOAT, CNNL_NOT_PROPAGATE_NAN, CNNL_REDUCE_NO_INDICES,
            CNNL_32BIT_INDICES, 0.0));

        // get workspace
        size_t workspaceSize = 0;
        checkCnnlError(cnnlGetReduceOpWorkspaceSize(context->cnnlHandle(),
                                                    inDesc, outDesc, reduceDesc,
                                                    &workspaceSize));
        int indicesSize = axes.size() * sizeof(int);
        BangPtr wsData = context->getWorkspace(workspaceSize + indicesSize);

        BangPtr indicesData = (char *)wsData + workspaceSize;
        context->copyBlobFromCPU(indicesData, axes.data(), indicesSize);

        // reduce
        float alpha = 1.f, beta = 0.f;
        checkCnnlError(cnnlReduce(
            context->cnnlHandle(), reduceDesc, wsData, workspaceSize, &alpha,
            inDesc, aData, indicesSize, indicesData, &beta, outDesc, cData));

        // Destories in CUDA does not require sync. But cuDNN does not state
        // whether sync is required before destories.
        checkCnnlError(cnnlDestroyTensorDescriptor(inDesc));
        checkCnnlError(cnnlDestroyTensorDescriptor(outDesc));
        checkCnnlError(cnnlDestroyReduceDescriptor(reduceDesc));
    }
};

REGISTER_KERNEL(Device::BANG, OpType::ReduceMean, DataType::Float32,
                ReduceMeanCnnl, "ReduceMean_cnnl_BANG_Float32");

}; // namespace infini
