/**
 * MIT License
 *
 * Copyright (C) 2024 Huawei Device Co., Ltd.
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
#include "AMapEventEmitters.h"

namespace facebook {
namespace react {
void MapViewEventEmitter::onPress(struct onPressEvent event) const {
    
    dispatchEvent("Press", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "latitude", event.latitude);
        payload.setProperty(runtime, "longitude", event.longitude);
        return payload;
    });
}
void MapViewEventEmitter::onPressPoi(struct onMapPoiEvent event) const {
    dispatchEvent("PressPoi", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "id", event.id);
        payload.setProperty(runtime, "name", event.name);
        auto latLng = jsi::Object(runtime);
        latLng.setProperty(runtime, "latitude", event.latLng.latitude);
        latLng.setProperty(runtime, "longitude", event.latLng.longitude);
        payload.setProperty(runtime, "position", latLng);
        return payload;
    });
}

void MapViewEventEmitter::onLongPress(struct onLongPressEvent event) const {
    dispatchEvent("LongPress", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "latitude", event.latitude);
        payload.setProperty(runtime, "longitude", event.longitude);
        return payload;
    });
}

static jsi::Object toJsiCameraPosition(jsi::Runtime &runtime, const MapViewEventEmitter::CameraPosition &cameraPosition) {
    auto target = jsi::Object(runtime);
    target.setProperty(runtime, "latitude", cameraPosition.target.latitude);
    target.setProperty(runtime, "longitude", cameraPosition.target.longitude);

    auto result = jsi::Object(runtime);
    result.setProperty(runtime, "target", target);
    result.setProperty(runtime, "zoom", cameraPosition.zoom);
    result.setProperty(runtime, "bearing", cameraPosition.bearing);
    result.setProperty(runtime, "tilt", cameraPosition.tilt);
    return result;
}

static jsi::Object toJsiLatLngBounds(jsi::Runtime &runtime, const MapViewEventEmitter::LatLngBounds &latLngBounds) {
    auto southwest = jsi::Object(runtime);
    southwest.setProperty(runtime, "latitude", latLngBounds.southwest.latitude);
    southwest.setProperty(runtime, "longitude", latLngBounds.southwest.longitude);

    auto northeast = jsi::Object(runtime);
    northeast.setProperty(runtime, "latitude", latLngBounds.northeast.latitude);
    northeast.setProperty(runtime, "longitude", latLngBounds.northeast.longitude);

    auto result = jsi::Object(runtime);
    result.setProperty(runtime, "southwest", southwest);
    result.setProperty(runtime, "northeast", northeast);
    return result;
}

void MapViewEventEmitter::onCameraMove(struct onCameraMoveEvent event) const {
    dispatchEvent("CameraMove", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "cameraPosition", toJsiCameraPosition(runtime, event.cameraPosition));
        payload.setProperty(runtime, "latLngBounds", toJsiLatLngBounds(runtime, event.latLngBounds));
        return payload;
    });
}

void MapViewEventEmitter::onCameraIdle(struct onCameraIdleEvent event) const {
    dispatchEvent("CameraIdle", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "cameraPosition", toJsiCameraPosition(runtime, event.cameraPosition));
        payload.setProperty(runtime, "latLngBounds", toJsiLatLngBounds(runtime, event.latLngBounds));
        return payload;
    });
}

void MapViewEventEmitter::onLoad(struct onLoadEvent event) const {
    dispatchEvent("Load", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        return payload;
    });
}


void MarkerEventEmitter::onPress(struct onPressEvent event) const {
    dispatchEvent("Press", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        return payload;
    });
}

void MarkerEventEmitter::onDragStart(struct onDragStartEvent event) const {
    dispatchEvent("DragStart", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        return payload;
    });
}

void MarkerEventEmitter::onDrag(struct onDragEvent event) const {
    dispatchEvent("Drag", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        return payload;
    });
}

void MarkerEventEmitter::onDragEnd(struct onDragEndEvent event) const {
    dispatchEvent("DragEnd", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "latitude", event.latitude);
        payload.setProperty(runtime, "longitude", event.longitude);
        return payload;
    });
}

void PolylineEventEmitter::onPress(struct onPressEvent event) const {
    dispatchEvent("Press", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        return payload;
    });
}
} // namespace react
} // namespace facebook