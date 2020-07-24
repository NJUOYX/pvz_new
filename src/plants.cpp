#include"plants.h"

int Plant::start(Plant_manager*p_m){
    p_m->image(pos,o_t,0);
    auto tar = p_m->get_target(this);
    auto res = tar->connection(this);
    if(res == INT_TRUE)
        
}