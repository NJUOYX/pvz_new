#ifndef __INCLUDE_PLANT_MANAGER__
#define __INCLUDE_PLANT_MANAGER__
#include "common.h"

class Plant_manager
{
public:
    Plant_manager() = default;
    int image(Position pos,PLANT_TYPE p_type,ACTION_TYPE a_type);
    Zombie* get_target(Position pos);
private:
};

#endif//__INCLUDE_PLANT__MANAGER__