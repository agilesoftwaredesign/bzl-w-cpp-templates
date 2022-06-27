#include "rtsmappert.h"
#include "core_messages/v16/Core.h"
#include "core_messages/Core.h"

namespace {
    template<typename PTYPE>
    void common(boardnet_2021::Rts &rts, const PTYPE &core) {
        rts.magicNumber = core.dummy;
    }

    template<const int V, typename PTYPE>
    typename std::enable_if<(V == 16), void>::type convertDetail(boardnet_2021::Rts &rts, const PTYPE &core) {
        // none
    }

    template<const int V, typename PTYPE>
    typename std::enable_if<(V == 0), void>::type convertDetail(boardnet_2021::Rts &rts, const PTYPE &core) {
        rts.detail = std::string{"happy "} + std::to_string(core.newDummy);
    }
}

template<int VERSION, typename PTYPE>
void RtsMapperT<VERSION, PTYPE>::convert(const PTYPE &core) {
    common(rts_, core);
    convertDetail<VERSION>(rts_, core);
}

// Class template instantiation -> https://en.cppreference.com/w/cpp/language/class_template
template class RtsMapperT<16, Core::v16::CoreRts>;
template class RtsMapperT<0, Core::CoreRts>;