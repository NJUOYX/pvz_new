#ifndef __LIB_STORAGE__
#define __LIB_STORAGE__
#include"common.h"
#include<stdlib.h>
#include<stdio.h>

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
};

typedef struct PIC_OBJ PIC_OBJ;

uint8_t screen[SCREEN_SIZE];

PIC_OBJ objs[OBJ_UNION_MAX_SIZE];

void init(FILE* init_const_file);




#endif//__LIB_STORAGE__