#ifndef __INCLUDE_CREATOR__
#define __INCLUDE_CREATOR__
#include"common.h"
class Creator
{
public:
    virtual int create_obj(OBJ_TYPE o_t,Position pos) = 0;
};


#endif//__INCLUDE_CREATOR__