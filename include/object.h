#include "common.h"

struct Effect
{
    
};

class Object
{
public:
    Object();
    Object(Position pos) : pos(pos) {}
    void set_pos(Position pos)
    {
        this->pos = pos;
    }
    Position my_position() const
    {
        return pos;
    }
    virtual int damage_tome(int damage)
    {
        hp -= damage;
        return hp;
    }
    virtual bool del_me() const
    {
        return hp <= 0;
    }
    virtual int start(Plant_manager *p_m)
    {
        return INT_TRUE;
    }
    virtual OBJ_TYPE my_type() const
    {
        return o_t;
    }

public:
    virtual int connection(Object *connecter)
    {
        if (this->connector != nullptr)
            return INT_FALSE;
        else
        {
            this->connector = connector;
            return INT_TRUE;
        }
    }

protected:
    OBJ_TYPE o_t = 0;
    Position pos;
    HEALTH_TYPE hp = 0;
};