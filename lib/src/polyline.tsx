import AMapPolyline ,{PolylineProps,voidEvent} from './polylineNativeComponent'
import React , {Component}  from 'react';
import type * as ReactNative from "react-native";

export default class Polyline extends Component<PolylineProps> {
 
  constructor(props: PolylineProps) {
    super(props);
  }

  render() {
    return (
      <AMapPolyline {...this.props} 
      onPress={(event: ReactNative.NativeSyntheticEvent<voidEvent>) => {
        this.props.onPress?.call(this, event);
      }}
      />
    );
  }
}