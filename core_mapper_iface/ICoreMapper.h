#ifndef CORE_EXP_ICOREMAPPER_H
#define CORE_EXP_ICOREMAPPER_H

class ICoreMapper {
public:
    virtual void parse(int version, const char* data) = 0;
    virtual void publishIfReady() = 0;
};

#endif //CORE_EXP_ICOREMAPPER_H
