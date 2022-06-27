#include "CoreMapper.h"

#include <iostream>
#include <memory>
#include "core_ros/rts_ros_mapper.h"
#include "core_ros/light_ros_mapper.h"

CoreMapper::CoreMapper() {
    // it's not wise to add them here
    addMapper(42, std::make_unique<RtsRosMapper>());
    addMapper(123, std::make_unique<LightRosMapper>());
}

void CoreMapper::addMapper(int datatype, std::unique_ptr<ICoreMapper> mapper) {
    mappers_[datatype] = std::move(mapper);
}

void CoreMapper::callback(const int version, const int datatype, const char *data) const {
    auto mapper_candidate = mappers_.find(datatype);
    if (mapper_candidate != mappers_.end()) {
        auto &mapper = mapper_candidate->second;
        mapper->parse(version, data);
        mapper->publishIfReady();

    } else {
        std::cerr << "not handled" << std::endl;
    }
}
