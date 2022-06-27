#ifndef CORE_EXP_LIGHT_ROS_MAPPER_H
#define CORE_EXP_LIGHT_ROS_MAPPER_H

#include "core_mapper_iface/ICoreMapper.h"
#include "boardnet/bn_light.h"

class LightRosMapper : public ICoreMapper {
public:
    void parse(int version, const char *data) override;

    void publishIfReady() override;

private:
    boardnet_2021::Light light_;
};


#endif //CORE_EXP_LIGHT_ROS_MAPPER_H
