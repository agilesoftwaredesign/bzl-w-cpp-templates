#ifndef CORE_EXP_RTSMAPPERT_H
#define CORE_EXP_RTSMAPPERT_H

#include "boardnet/bn_rts.h"

template<int VERSION, typename PTYPE>
class RtsMapperT {
public:
    void convert(const PTYPE &core);

    boardnet_2021::Rts get() const noexcept {
        return rts_;
    }

private:
    boardnet_2021::Rts rts_;
};

#endif //CORE_EXP_RTSMAPPERT_H
