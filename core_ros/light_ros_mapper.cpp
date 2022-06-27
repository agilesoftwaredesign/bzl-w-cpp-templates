#include "light_ros_mapper.h"

#include <iostream>

#include "core_messages/Light.h"
#include "core_messages/Core.h"
#include "converter_lib/lightmappert.h"

void LightRosMapper::parse(int version, const char *data) {
    auto core_data = reinterpret_cast<const Core::CoreLight*>(data);
    auto mapper = LightMapperT<16, Core::CoreLight>();
    mapper.convert(*core_data);
    light_ = mapper.get();
}

void LightRosMapper::publishIfReady() {
    std::cout << "Hi from lights -> " << light_ << std::endl;
}
