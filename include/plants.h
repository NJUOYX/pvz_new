#ifndef __INCLUDE_PLANTS__
#define __INCLUDE_PLANTS__
#include"common.h"
#include"object.h"
class Plant:public Object
{
public:
    Plant(Position pos):Object(pos){}
    virtual int start()override;
private:
};

#endif//__INCLUDE_PLANTS__