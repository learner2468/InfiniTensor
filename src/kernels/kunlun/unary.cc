#include "operators/unary.h"
#include "kunlun/kunlun_kernel_without_config.h"
#include "kunlun/kunlun_runtime.h"

namespace infini {
class ReluXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::relu<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class SigmoidXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::sigmoid<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class TanhXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::tanh<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class SquareXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::square<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class SqrtXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::sqrt<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class RsqrtXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::rsqrt<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class ExpXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::exp<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class CeilXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::ceil<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class ClipXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<ClipObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        float min = op->getMin().value();
        float max = op->getMax().value();

        auto ret = baidu::xpu::api::clip<float>(context->KUNLUNHandle(),
                                                (float *)aData, (float *)cData,
                                                len, min, max);
        assert(ret == 0);
        return;
    }
};

class FloorXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::floor<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class NegXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::neg<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class CopyXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &op,
                 const RuntimeObj *_context) const override {
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::copy<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class ReciprocalXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::reciprocal<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class AbsXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::abs<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class ATanXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<UnaryObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);

        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();

        auto ret = baidu::xpu::api::arctan<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);
        assert(ret == 0);
        return;
    }
};

class LogXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<LogObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto aDim = op->getInputs(0)->getDims();
        std::vector<int> divDim = {
            1,
        };
        auto len = op->getInputs(0)->size();
        // get ptr of tempspace
        KUNLUNPtr temp = context->getWorkspace(len * sizeof(float));
        LogObj::LogType type = op->getType();
        // get output of xpu::api::loge(x)
        auto ret = baidu::xpu::api::log<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)temp, len);
        // get ptr of divider
        KUNLUNPtr dd =
            (float *)(context->getWorkspace((1 + len) * sizeof(float))) + len;
        // choose from logE, log2, log10
        switch (type) {
            float constant;
        case LogObj::LogE:
            // if use loge, copy from temp to cData
            ret = baidu::xpu::api::copy<float>(
                context->KUNLUNHandle(), (float *)temp, (float *)cData, len);
            break;
        case LogObj::Log2:
            constant = std::log(2);
            context->copyBlobFromCPU(dd, &constant, sizeof(float));
            ret = baidu::xpu::api::broadcast_div<float>(
                context->KUNLUNHandle(), (float *)temp, (float *)dd,
                (float *)cData, aDim, divDim);
            break;
        case LogObj::Log10:
            constant = std::log(10);
            context->copyBlobFromCPU(dd, &constant, sizeof(float));
            ret = baidu::xpu::api::broadcast_div<float>(
                context->KUNLUNHandle(), (float *)temp, (float *)dd,
                (float *)cData, aDim, divDim);
            break;
        default:
            printf("LogType not support!");
            break;
        }
        assert(ret == 0);
        return;
    }
};

class CosXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<CosObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::cos<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

class SinXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<SinObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::sin<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

class TanXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<TanObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::tan<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

class SinhXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<SinHObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::sinh<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

class CoshXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<CosHObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::cosh<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

class ErfXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<ErfObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::erf<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

class ACosXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<ACosObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::arccos<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

class ACoshXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<ACosHObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::acosh<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

class ASinXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<ASinObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::arcsin<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

class ASinhXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<ASinHObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::asinh<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

class ATanhXdnn : public KUNLUNKernelWithoutConfig {
    void compute(const Operator &_op,
                 const RuntimeObj *_context) const override {
        auto op = as<ATanHObj>(_op);
        auto context = dynamic_cast<const KUNLUNRuntimeObj *>(_context);
        void *const aData = (op->getInputs(0)->getRawDataPtr<void *>());
        void *const cData = (op->getOutput()->getRawDataPtr<void *>());
        auto len = op->getInputs(0)->size();
        auto ret = baidu::xpu::api::atanh<float>(
            context->KUNLUNHandle(), (float *)aData, (float *)cData, len);

        assert(ret == 0);
        return;
    }
};

REGISTER_KERNEL(Device::KUNLUN, OpType::Relu, DataType::Float32, ReluXdnn,
                "Relu_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Sigmoid, DataType::Float32, SigmoidXdnn,
                "Sigmoid_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Tanh, DataType::Float32, TanhXdnn,
                "Tanh_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Square, DataType::Float32, SquareXdnn,
                "Square_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Sqrt, DataType::Float32, SqrtXdnn,
                "Sqrt_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Rsqrt, DataType::Float32, RsqrtXdnn,
                "Rsqrt_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Exp, DataType::Float32, ExpXdnn,
                "Exp_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Ceil, DataType::Float32, CeilXdnn,
                "Ceil_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Clip, DataType::Float32, ClipXdnn,
                "Clip_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Floor, DataType::Float32, FloorXdnn,
                "Floor_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Neg, DataType::Float32, NegXdnn,
                "Neg_xdnn_KUNLUN_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Reciprocal, DataType::Float32,
                ReciprocalXdnn, "Reciprocal_xdnn_KUNLUN_Float32");

REGISTER_KERNEL(Device::KUNLUN, OpType::Reshape, DataType::Float32, CopyXdnn,
                "Reshape_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Flatten, DataType::Float32, CopyXdnn,
                "Flatten_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Identity, DataType::Float32, CopyXdnn,
                "Identity_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Abs, DataType::Float32, AbsXdnn,
                "Abs_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Atan, DataType::Float32, ATanXdnn,
                "Atan_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Log, DataType::Float32, LogXdnn,
                "Log_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Cos, DataType::Float32, CosXdnn,
                "Cos_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Sin, DataType::Float32, SinXdnn,
                "Sin_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Tan, DataType::Float32, TanXdnn,
                "Tan_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Sinh, DataType::Float32, SinhXdnn,
                "Sinh_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Cosh, DataType::Float32, CoshXdnn,
                "Cosh_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Erf, DataType::Float32, ErfXdnn,
                "Erf_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Acos, DataType::Float32, ACosXdnn,
                "ACos_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Acosh, DataType::Float32, ACoshXdnn,
                "ACosh_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Asin, DataType::Float32, ASinXdnn,
                "ASin_xdnn_Float32");
REGISTER_KERNEL(Device::KUNLUN, OpType::Asinh, DataType::Float32, ASinhXdnn,
                "ASinh_xdnn_Float3 2");
REGISTER_KERNEL(Device::KUNLUN, OpType::Atanh, DataType::Float32, ATanhXdnn,
                "ATanh_xdnn_Float32");
}; // namespace infini
