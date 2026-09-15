//
// Created on 2024/11/13.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "Amap3dSpec.h"

using namespace rnoh;
using namespace facebook;

static jsi::Value __hostFunction_NativeAmap3dCxxModuleSpecJSI_initSDK(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                      const jsi::Value *args, size_t count) {
    return jsi::Value(static_cast<ArkTSTurboModule &>(turboModule).call(rt, "initSDK", args, count));
}

static jsi::Value __hostFunction_NativeAmap3dCxxModuleSpecJSI_getVersion(jsi::Runtime &rt,
                                                                         react::TurboModule &turboModule,
                                                                         const jsi::Value *args, size_t count) {
    return jsi::Value(static_cast<ArkTSTurboModule &>(turboModule).call(rt, "getVersion", args, count));
}


NativeAmap3dSpecJSI::NativeAmap3dSpecJSI(const ArkTSTurboModule::Context ctx, const std::string name)
    : ArkTSTurboModule(ctx, name) {
    methodMap_["initSDK"] = MethodMetadata{1, __hostFunction_NativeAmap3dCxxModuleSpecJSI_initSDK};
    methodMap_["getVersion"] = MethodMetadata{0, __hostFunction_NativeAmap3dCxxModuleSpecJSI_getVersion};
}