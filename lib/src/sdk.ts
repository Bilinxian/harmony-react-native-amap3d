import NativeAMapSdk from './NativeAMapSdk'

const AMapSdk = {
  init(apiKey: string) {
    NativeAMapSdk?.initSDK(apiKey);
  },
  getVersion(): Promise<string> | undefined {
    return NativeAMapSdk?.getVersion();
  }
}

export default AMapSdk
