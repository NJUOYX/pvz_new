#ifndef __INCLUDE_MANAGER__
#define __INCLUDE_MANAGER__
#include "plant_manager.h"
#include "zombie_manager.h"
#include "creator.h"
#include "object.h"
#include <list>
#include<iostream>
class Manager : public Plant_manager, Zombie_manager, Creator
{
public:
    Manager() = default;
    int exec();
    int create_obj(OBJ_TYPE o_t, Position pos) override;
    int image(Position pos,OBJ_TYPE o_t,ACTION_TYPE a_t);
    Object* get_target(Object*sender);
private:
    Object*get_obj_type(OBJ_TYPE o_t);
private:
    std::list<Object *> obj_ptrs;
    std::list<Object*>obj_ptrs_wait_to_add;
    int begin = 0;
};
#endif //__INCLUDE_MANAGER__