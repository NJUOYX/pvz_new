#include"object.h"

class Obj_lib
{
private:
    const char* lib_file;
public:
    Obj_lib(const char* lib_file):lib_file(lib_file)
    {
        
    }
    Object* get_obj(OBJ_TYPE o_t);
};

