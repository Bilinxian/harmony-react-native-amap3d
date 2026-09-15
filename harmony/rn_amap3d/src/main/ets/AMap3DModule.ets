/**
 * MIT License
 *
 * Copyright (C) 2023 Huawei Device Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

import { TurboModule, TurboModuleContext } from '@rnoh/react-native-openharmony/ts';
import { MapsInitializer } from '@amap/amap_lbs_map3d';
import { AMapPrivacyAgreeStatus, AMapPrivacyShowStatus, AMapPrivacyInfoStatus } from '@amap/amap_lbs_common';

export class AMap3DModule extends TurboModule {
  constructor(ctx: TurboModuleContext) {
    super(ctx);
  }

  initSDK(key: string) {
    MapsInitializer.setApiKey(key);

    try {
      const context = this.ctx.uiAbilityContext;
      MapsInitializer.initialize(context);
      MapsInitializer.updatePrivacyShow(AMapPrivacyShowStatus.DidShow, AMapPrivacyInfoStatus.DidContain, context)
      MapsInitializer.updatePrivacyAgree(AMapPrivacyAgreeStatus.DidAgree, context)
    } catch (error) {
    }
  }

  getVersion(): string {
    return MapsInitializer.getVersion()
  }
}