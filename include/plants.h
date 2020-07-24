#ifndef __INCLUDE_PLANTS__
#define __INCLUDE_PLANTS__
#include"common.h"
#include"object.h"
#include"plant_manager.h"
class Plant:public Object
{
public:
    Plant(Position pos):Object(pos){}
    virtual int start(Plant_manager*p_m)override;
private:
};

#endif//__INCLUDE_PLANTS__