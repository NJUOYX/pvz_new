#include "common.h"

class Object
{
public:
    Object();
    Object(Position pos);
    void set_pos(Position pos);
    Position my_position() const;
    virtual int damage_tome(int damage);
    virtual int del_me();
    virtual int start();

public:
    virtual int connection(Object *connecter);

private:
    OBJ_TYPE o_t;
};