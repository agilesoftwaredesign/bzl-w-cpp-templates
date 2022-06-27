#ifndef CORE_EXP_LIGHTMAPPERT_H
#define CORE_EXP_LIGHTMAPPERT_H

#include "boardnet/bn_light.h"

template<int VERSION, typename PTYPE>
class LightMapperT {
public:
    void convert(const PTYPE &core);

    boardnet_2021::Light get() const noexcept {
        return light_;
    }

private:
    boardnet_2021::Light light_;
};

#endif //CORE_EXP_LIGHTMAPPERT_H
