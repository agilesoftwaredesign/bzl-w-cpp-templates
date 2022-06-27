#include "lightmappert.h"
#include "core_messages/Light.h"
#include "core_messages/Core.h"

namespace {
    template<int V, typename PTYPE>
    typename std::enable_if<(V == 16), int>::type color(const PTYPE &ptype) {
        return 55;
    }

    template<int V, typename PTYPE>
    typename std::enable_if<(V == 1), int>::type color(const PTYPE &ptype) {
        return 99;
    }
}

template<int VERSION, typename PTYPE>
void LightMapperT<VERSION, PTYPE>::convert(const PTYPE &core) {
    light_.x = core.x - 100;
    light_.y = -core.y + 100;
    light_.color = color<VERSION>(core);
}

// Class template instantiation -> https://en.cppreference.com/w/cpp/language/class_template
template
class LightMapperT<16, Core::CoreLight>;