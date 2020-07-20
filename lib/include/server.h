#ifndef __LIB_SERVER__
#define __LIB_SERVER__
#include"storage.h"
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>

#define PORT 8087
#define IP "127.0.0.1"
#define WAIT_TIMES 5
void init_connection();

void error_handling(const char* message);

int sending(uint8_t* screen_buffer,uint32_t screen_buffer_size,PIC_OBJ*obj_buffer,uint32_t obj_buffer_size);

#endif//__LIB_SERVER__