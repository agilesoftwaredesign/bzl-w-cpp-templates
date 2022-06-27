#ifndef CORE_EXP_RTS_ROS_MAPPER_H
#define CORE_EXP_RTS_ROS_MAPPER_H

#include "core_mapper_iface/ICoreMapper.h"
#include "boardnet/bn_rts.h"

class RtsRosMapper : public ICoreMapper {
public:
    void parse(int version, const char *data) override;

    void publishIfReady() override;

private:
    boardnet_2021::Rts rts_;
};

#endif //CORE_EXP_RTS_ROS_MAPPER_H
