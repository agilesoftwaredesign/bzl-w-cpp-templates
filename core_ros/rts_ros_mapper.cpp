#include "core_ros/rts_ros_mapper.h"

#include <iostream>

#include "converter_lib/rtsmappert.h"
#include "core_messages/v16/Core.h"
#include "core_messages/Core.h"

void RtsRosMapper::parse(const int version, const char *data) {
    if (version == 16) {
        const auto core_data = reinterpret_cast<const Core::v16::CoreRts*>(data);
        RtsMapperT<16, Core::v16::CoreRts> mapper;
        mapper.convert(*core_data);
        rts_ = mapper.get();

    } else {
        // always take "latest"
        const auto core_data = reinterpret_cast<const Core::CoreRts*>(data);
        RtsMapperT<0, Core::CoreRts> mapper;
        mapper.convert(*core_data);
        rts_ = mapper.get();
    }
}

void RtsRosMapper::publishIfReady() {
    std::cout << "Publish (ROS): " << rts_ << std::endl;
}
