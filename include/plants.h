#ifndef __INCLUDE_PLANTS__
#define __INCLUDE_PLANTS__
#include"common.h"
#include"object.h"
class Plant:public Object
{
public:
    Plant(Position pos):Object(pos){}
    virtual int damage_tome(int damage)override;
    virtual int del_me()override;
    virtual int connection(Object*connecter)override;
private:
    Position pos;
    uint32_t health;
};

#endif//__INCLUDE_PLANTS__