//
// Created on 2024/11/13.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#pragma once

#include <ReactCommon/TurboModule.h>
#include "RNOH/ArkTSTurboModule.h"

namespace rnoh {
class JSI_EXPORT NativeAmap3dSpecJSI : public ArkTSTurboModule {
public:
    NativeAmap3dSpecJSI(const ArkTSTurboModule::Context ctx, const std::string name);
};
}