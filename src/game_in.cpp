#include"game_in.h"

int Game_in::start()
{
    while(state == RUN)
    {
        Position pos;
        OBJ_TYPE o_t;
        while(get_info(&pos,&o_t) == 0);
        manager->create_obj(o_t,pos);
    }
}

int Game_in::get_info(Position*pos, OBJ_TYPE*o_t)
{
    std::cin>>pos->row>>pos->col>>(*o_t);
    return 0;
}