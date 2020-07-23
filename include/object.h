#include "common.h"

class Object
{
public:
    Object();
    Object(Position pos):pos(pos){}
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
        hp-=damage;
        return hp;
    }
    virtual bool del_me()const
    {
        return hp<=0;
    }
    virtual int start()
    {
        return INT_TRUE;
    }
    virtual OBJ_TYPE my_type()const
    {
        return o_t;
    }

public:
    virtual int connection(Object *connecter)
    {
        if(this->connector != nullptr)
            return INT_FALSE;
        else
        {
            this->connector = connector;
            return INT_TRUE;
        }
    }

private:
    OBJ_TYPE o_t = 0;
    Position pos;
    Object*connector = nullptr;
    HEALTH_TYPE hp = 0;

};