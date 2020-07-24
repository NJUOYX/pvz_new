#ifndef __INCLUDE_MANAGER__
#define __INCLUDE_MANAGER__
#include "creator.h"
#include "object.h"
#include <list>
#include<iostream>
class Manager : public Creator
{
public:
    Manager() = default;
    int exec();
    virtual int create_obj(OBJ_TYPE o_t, Position pos);
    virtual int image(Position pos,OBJ_TYPE o_t,ACTION_TYPE a_t);
    virtual Object* get_target(Object*sender);
private:
    Object*get_obj_type(OBJ_TYPE o_t);
protected:
    std::list<Object *> obj_ptrs;
    std::list<Object*>obj_ptrs_wait_to_add;
    int begin = 0;
};
#endif //__INCLUDE_MANAGER__