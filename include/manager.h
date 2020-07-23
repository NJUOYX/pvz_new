#ifndef __INCLUDE_MANAGER__
#define __INCLUDE_MANAGER__
#include "plant_manager.h"
#include "zombie_manager.h"
#include "creator.h"
#include "object.h"
#include <list>
class Manager : public Plant_manager, Zombie_manager, Creator
{
public:
    Manager() = default;
    int exec()
    {
        begin = 1;
        std::list<std::list<Object *>::iterator> wait_del;
        while (begin)
        {
            for (auto i = obj_ptrs.begin(); i != obj_ptrs.end(); ++i)
            {
                auto j = *i;

                if ((*i)->del_me())
                    wait_del.push_back(i);
                else
                    (*i)->start();
            }
            for(auto i : wait_del)
                obj_ptrs.erase(i);
            wait_del.clear();
            for(auto i: obj_ptrs_wait_to_add)
                obj_ptrs.push_back(i);
            obj_ptrs_wait_to_add.clear();
        }
    }
    int create_obj(OBJ_TYPE o_t, Position pos) override
    {
        auto new_obj = get_obj_type(o_t);
        new_obj->set_pos(pos);
        obj_ptrs_wait_to_add.push_back(new_obj);
        return 0;
    }

private:
    Object*get_obj_type(OBJ_TYPE o_t);
private:
    std::list<Object *> obj_ptrs;
    std::list<Object*>obj_ptrs_wait_to_add;
    int begin = 0;
};
#endif //__INCLUDE_MANAGER__