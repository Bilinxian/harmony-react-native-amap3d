//
// Created on 2024/11/13.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#pragma once

#include "RNOH/Package.h"

namespace rnoh {
    class Amap3dPackage : public Package {
    public:
        Amap3dPackage(Package::Context ctx) : Package(ctx) {}
        std::unique_ptr<TurboModuleFactoryDelegate> createTurboModuleFactoryDelegate()
        override;
    };
} // namespace rnoh