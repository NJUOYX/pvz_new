#include "manager.h"

int Manager::exec()
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
        for (auto i : wait_del)
            obj_ptrs.erase(i);
        wait_del.clear();
        for (auto i : obj_ptrs_wait_to_add)
            obj_ptrs.push_back(i);
        obj_ptrs_wait_to_add.clear();
    }
}

int Manager::create_obj(OBJ_TYPE o_t, Position pos)
{
    auto new_obj = get_obj_type(o_t);
    new_obj->set_pos(pos);
    obj_ptrs_wait_to_add.push_back(new_obj);
    return 0;
}

int Manager::image(Position pos, OBJ_TYPE o_t, ACTION_TYPE a_t)
{
    std::cout << "info: position: [" << pos.row << ", " << pos.col << "]"
              << "\t"
              << "Object Type" << o_t << "Action_Type:" << a_t << std::endl;
    std::cout << "--------------" << std::endl;
    return 0;
}

Object *Manager::get_target(Object *sender)
{
    DISTANCE dis = INT16_MAX;
    Object *target = nullptr;
    for (auto i : obj_ptrs)
    {
        auto n_dis = i->my_position().distance(sender->my_position()) < dis;
        if (n_dis < dis)
        {
            dis = n_dis;
            target = i;
        }
    }
    return target;
}