
import AMapView, { Location, MapViewProps, voidEvent } from './map-viewNativeComponent'
import React, { Component } from 'react';
import type * as ReactNative from "react-native";
import {NativeMethods} from "react-native";
import { LatLng, CameraPosition, LatLngBounds, onCameraEvent, MapPoi, moveCameraCommands } from './map-viewNativeComponent'

export default class MapView extends Component<MapViewProps> {
  constructor(props: MapViewProps) {
    super(props);
  }

  ref: React.ElementRef<typeof AMapView> | null = null;

  /**
   * 移动视角
   */
  moveCamera(cameraPosition: CameraPosition, duration = 0) {
      if (this.ref) {
		    moveCameraCommands.moveCamera(
          this.ref,
          cameraPosition,
          duration
		  );
      }
  }

  render() {
    return (
      <AMapView {...this.props} ref={(ref) => (this.ref = ref)}
        {...this.props}
        onPress={(event: ReactNative.NativeSyntheticEvent<LatLng>) => {
          if (event.nativeEvent.latitude) {
            this.props.onPress?.call(this, event);
          }
        }}
        onLongPress={(event: ReactNative.NativeSyntheticEvent<LatLng>) => {
          if (event.nativeEvent.latitude) {
            this.props.onLongPress?.call(this, event);
          }
        }}
        onCameraMove={(event: ReactNative.NativeSyntheticEvent<CameraPosition>) => {
          if (event.nativeEvent.targetValue?.latitude) {
            this.props.onCameraMove?.call(this, event);
          }
        }}
        onCameraIdle={(event: ReactNative.NativeSyntheticEvent<CameraPosition>) => {
          if (event.nativeEvent.targetValue?.latitude) {
            this.props.onCameraIdle?.call(this, event);
          }
        }}
        onPressPoi={(event: ReactNative.NativeSyntheticEvent<MapPoi>) => {
          if (event.nativeEvent.position.latitude) {
            this.props.onPressPoi?.call(this, event);
          }
        }}
        onLocation={(event: ReactNative.NativeSyntheticEvent<Location>) => {
          this.props.onLocation?.call(this, event);
        }}
        onLoad={(event: ReactNative.NativeSyntheticEvent<voidEvent>) => {
          this.props.onLoad?.call(this, event);
        }}
      />
    );
  }
}