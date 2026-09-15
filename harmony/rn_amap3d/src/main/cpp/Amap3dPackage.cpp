//
// Created on 2024/11/13.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "Amap3dPackage.h"
#include "Amap3dSpec.h"


using namespace rnoh;
using namespace facebook;

class Amap3dPackageFactoryDelegate : public TurboModuleFactoryDelegate {

    public:
    SharedTurboModule createTurboModule(Context ctx, const std::string &name) const override {
        if (name == "AMapSdk") {
            return std::make_shared<NativeAmap3dSpecJSI>(ctx, name);
        }
        return nullptr;
    };
};

std::unique_ptr<TurboModuleFactoryDelegate> Amap3dPackage::createTurboModuleFactoryDelegate() {
    return std::make_unique<Amap3dPackageFactoryDelegate>();
}