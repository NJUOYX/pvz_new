#ifndef __INCLUDE_PLANT_MANAGER__
#define __INCLUDE_PLANT_MANAGER__
#include "common.h"
#include"manager.h"
class Plant_manager:public Manager
{
public:
    Plant_manager() = default;
    int image(Position pos,PLANT_TYPE p_type,ACTION_TYPE a_type);
    Object* get_target(Object* sender)override;
private:

};

#endif//__INCLUDE_PLANT__MANAGER__