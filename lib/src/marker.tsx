

import AMapMarker ,{MarkerProps,LatLng,voidEvent} from './markerNativeComponent'
import React , {Component}  from 'react';
import type * as ReactNative from "react-native";

export default class Marker extends Component<MarkerProps> {
 
  constructor(props: MarkerProps) {
    super(props);
  }

  name = name;


  render() {
    return (
      <AMapMarker {...this.props} 
      onPress={(event: ReactNative.NativeSyntheticEvent<voidEvent>) => {
        this.props.onPress?.call(this, event);
        
      }}
      onDragEnd={(event: ReactNative.NativeSyntheticEvent<LatLng>) => {
        this.props.onDragEnd?.call(this, event);
      }}
      />
    );
  }
}
const name = "AMapMarker";