#ifndef CORE_EXP_BN_LIGHT_H
#define CORE_EXP_BN_LIGHT_H

#include <ostream>

namespace boardnet_2021 {
    struct Light{
        int x;
        int y;
        int z;
        int color;

        friend std::ostream &operator<<(std::ostream &os, const Light &light) {
            os << "x: " << light.x << " y: " << light.y << " z: " << light.z << " color: " << light.color;
            return os;
        }
    };
}

#endif //CORE_EXP_BN_LIGHT_H
