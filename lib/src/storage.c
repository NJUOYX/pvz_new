#include "include/storage.h"

uint8_t screen[SCREEN_SIZE];
PIC_OBJ objs[OBJ_UNION_MAX_SIZE];

void init(const char *init_filename)
{
    uint8_t buffer;
    int res = 0;
    OBJ_ID idx = 0;
    FILE *init_const_file = NULL;
    init_const_file = fopen(init_filename, "rb");
    if (init_const_file == NULL)
    {
        printf("init pic file read failed\n");
        fclose(init_const_file);
        return;
    }
    do
    {
        res = fread(&buffer, sizeof(uint8_t), 1, init_const_file);
        screen[idx++] = buffer;
    } while (res == 1);
    fclose(init_const_file);
    return;
}

OBJ_ID alloc_obj()
{
    for (OBJ_ID i = 0; i < OBJ_UNION_MAX_SIZE; ++i)
    {
        if (objs[i].v == 0)
        {
            objs[i].v = 1;
            return i;
        }
    }
    return -1;
}

OBJ_ID create_obj(const char *obj_pic_filename)
{
    uint8_t buffer;
    int res = 0;
    OBJ_ID idx = 0;
    FILE *obj_file = NULL;
    OBJ_ID o_id = -1;
    if((o_id = alloc_obj()) = -1)
    {
        printf("no available obj.\n");
        return -1;
    }
    obj_file = fopen(obj_pic_filename, "rb");
    if (ojb_file == NULL)
    {
        printf("obj file %s open failed.\n", obj_pic_filename);
        fclose(obj_file);
        return -1;
    }
    do
    {
        res = fread(&buffer,sizeof(uint8_t),1,obj_file);
        objs[o_id].pixel[idx++] = buffer;
    } while (res == 1);
    fclose(obj_file);
    return o_id;
}

int check_obj_id(OBJ_ID o_id)
{
    if(o_id == -1)
    {
        printf("unexsist obj.\n");
        return 0;
    }
    return 1;
}

int del_obj(OBJ_ID o_id)
{
    if(check_obj_id(o_id))
    {
        printf("del a unexsist obj.\n");
        return -1;
    }
    objs[o_id].v = 0;
    return 0;
}

int insert_obj(OBJ_ID o_id,uint16_t start_x,uint16_t start_y,uint16_t end_x,uint16_t end_y,uint16_t speed)
{
    if(check_obj_id(o_id))
    {
        printf("insert failed.\n");
        return -1;
    }
    objs[o_id].start_x = start_x;
    objs[o_id].start_y = start_y;
    objs[o_id].end_x = end_x;
    objs[o_id].end_y = end_y;
    objs[o_id].show = 0;
    objs[o_id].speed = speed;
    objs[o_id].start = 0;
    objs[o_id].cur_x = start_x;
    objs[o_id].cur_y = start_y;
    return 0;
}

int start_obj(OBJ_ID o_id)
{
    if(check_obj_id(o_id))
    {
        printf("start failed.\n");
        return -1;
    }
    objs[o_id].start = 1;
}

int show_obj(OBJ_ID o_id)
{
    if(check_obj_id(o_id))
    {
        printf("show failed.\n");
        return -1;
    }
    objs[o_id].show = 1;
}

int hide_obj(OBJ_ID o_id)
{
    if(check_obj_id(o_id))
    {
        printf("hide failed.\n");
        return -1;
    }
    objs[o_id].show = 0;
}