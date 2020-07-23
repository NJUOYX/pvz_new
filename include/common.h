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

struct Position
{
    uint16_t col;
    uint16_t row;
};
class Plant_manager;
class Zombie_manager;
class Plant;
class Zombie;
class Object;


#endif//__INCLUDE_COMMON__