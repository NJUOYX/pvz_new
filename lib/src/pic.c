#include"include/pic.h"

void play()
{
    for(OBJ_ID i = 0;i<OBJ_UNION_MAX_SIZE;++i)
    {
        if(objs[i].v == 1)
        {
            objs[i].cur_x +=objs[i].speed;
            if(objs[i].cur_x<0 || objs[i].cur_x>objs[i].end_x)
                del_obj(i);
        }
    }
}