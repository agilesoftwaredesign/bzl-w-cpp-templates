#include <iostream>

#include "core_mapper/CoreMapper.h"

struct ThisIsNotCoreButEqualInMemoryStructureToCore {
    int dummy;
    int newDummy;
};

struct ThisIsNotCoreLightButEqualInMemoryStructure {
    int x;
    int y;
    int color;
};

int main() {
    std::cout << "= WELCOME =" << std::endl;

    CoreMapper coreMapper;

    ThisIsNotCoreButEqualInMemoryStructureToCore rts{33, 77};
    coreMapper.callback(1, 42, reinterpret_cast<const char *>(&rts));

    ThisIsNotCoreLightButEqualInMemoryStructure light{1, 2, 10};
    coreMapper.callback(1, 123, reinterpret_cast<const char *>(&light));

    std::cout << "- BYE -" << std::endl;
}