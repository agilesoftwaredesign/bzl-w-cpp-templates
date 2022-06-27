#ifndef CORE_EXP_BN_RTS_H
#define CORE_EXP_BN_RTS_H

#include <string>
#include <ostream>

namespace boardnet_2021 {
    struct Rts {
        int magicNumber;
        std::string detail;

        friend std::ostream &operator<<(std::ostream &os, const Rts &rts) {
            os << "magicNumber: " << rts.magicNumber << " detail: " << rts.detail;
            return os;
        }
    };
}

#endif //CORE_EXP_BN_RTS_H
