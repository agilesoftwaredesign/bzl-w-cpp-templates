#ifndef CORE_EXP_COREMAPPER_H
#define CORE_EXP_COREMAPPER_H

#include <memory>
#include <map>
#include <set>

#include "core_mapper_iface/ICoreMapper.h"

class CoreMapper {
public:
    CoreMapper();
    void addMapper(int datatype, std::unique_ptr<ICoreMapper> mapper);
    void callback(int version, int datatype, const char *data) const;

private:
    std::map<int, std::unique_ptr<ICoreMapper>> mappers_;
};


#endif //CORE_EXP_COREMAPPER_H
