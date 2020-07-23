#ifndef __INCLUDE_GAME_IN__
#define __INCLUDE_GAME_IN__
#include"manager.h"
#include<thread>
#include<functional>
#include<iostream>
constexpr auto RUN = 1;
constexpr auto STOP = 0;
class Game_in
{
public:
    Game_in(Manager*m):manager(m),t(std::thread(std::mem_fn(&Game_in::start), this)){}
    ~Game_in(){
        state = STOP;
        t.join();
    }
private:
    int start();
    int get_info(Position*pos, OBJ_TYPE*o_t);
private:
    Manager*manager;
    std::thread t;
    int state = RUN;
};

#endif //__INCLUDE_GAME_IN__