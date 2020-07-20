#ifndef __LIB_STORAGE__
#define __LIB_STORAGE__
#include"common.h"


#define SCREEN_WIDTH 480 
#define SCREEN_HIGHT 240
#define SCREEN_SIZE SCREEN_WIDTH*SCREEN_HIGHT

#define OBJ_WIDTH 20
#define OBJ_HIGHT 20
#define OBJ_SIZE OBJ_WIDTH*OBJ_HIGHT

#define OBJ_UNION_MAX_SIZE 40

struct PIC_OBJ{
    uint8_t pixel[OBJ_SIZE];
    uint16_t start_x;
    uint16_t start_y;
    uint16_t end_x;
    uint16_t end_y;
    uint16_t speed;
    uint8_t start;
    uint8_t show;
    uint8_t v;
    uint16_t cur_x;
    uint16_t cur_y;
};

typedef struct PIC_OBJ PIC_OBJ;

extern uint8_t screen[SCREEN_SIZE];

extern PIC_OBJ objs[OBJ_UNION_MAX_SIZE];

typedef int OBJ_ID;

void init(const char* init_filename);

OBJ_ID create_obj(const char* obj_pic_filename);

int del_obj(OBJ_ID o_id);

int insert_obj(OBJ_ID o_id,uint16_t start_x,uint16_t start_y,uint16_t end_x,uint16_t end_y,uint16_t speed);

int show_obj(OBJ_ID o_id);

int hide_obj(OBJ_ID o_id);

int start_obj(OBJ_ID o_id);

OBJ_ID alloc_obj();

int check_obj_id(OBJ_ID o_id);
#endif//__LIB_STORAGE__