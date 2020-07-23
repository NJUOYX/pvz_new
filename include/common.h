#ifndef __INCLUDE__COMMON__
#define __INCLUDE_COMMON__

using uint8_t = unsigned char; 
using uint16_t = unsigned short;
using uint32_t = unsigned int;

using PLANT_TYPE = uint32_t; 
using ACTION_TYPE = uint32_t;
using OBJ_TYPE = uint32_t;
using HEALTH_TYPE = uint32_t;
using DAMAGE_TYPE = uint32_t;
using MOVE_SPEED = uint32_t;

using DISTANCE = uint16_t;
constexpr auto PLANT = 1;
constexpr auto ZOMBIE = 0;
constexpr auto INT_FALSE = -1;
constexpr auto INT_TRUE = 0;
struct Position
{
    DISTANCE col=0;
    DISTANCE row=0;
    DISTANCE distance(Position p)const
    {
        if(p.col-col>0)
            return p.col-col;
        else
            return col-p.col;
    }
};
class Plant_manager;
class Zombie_manager;
class Plant;
class Zombie;
class Object;


#endif//__INCLUDE_COMMON__