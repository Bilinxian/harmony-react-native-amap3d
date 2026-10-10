import AMapSdk from './NativeAMapSdk'

export function init(apiKey: string) {
  AMapSdk.initSDK(apiKey);
}

export function getVersion(): Promise<string> {
  return AMapSdk.getVersion();
}
