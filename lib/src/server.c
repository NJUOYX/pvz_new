#include "include/server.h"

int serv_sock = 0;
int clnt_sock = 0;
struct sockaddr_in serv_addr;
struct sockaddr_in clnt_addr;
socklen_t clnt_addr_size;

void init_connection()
{
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket() error.");
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);
    if (bind(serv_sock, &serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");

    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    clnt_addr_size = sizeof(clnt_addr_size);
    clnt_sock = accept(serv_sock, &clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1)
        error_handling("accept() error");
}

void error_handling(const char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(-1);
    return;
}

int sending(uint8_t *screen_buffer, uint32_t screen_buffer_size, PIC_OBJ *obj_buffer, uint32_t obj_buffer_size)
{

    uint8_t screen_buffer_ans = 0;
    uint8_t obj_buffer_ans = 0;
    int wait = 0;
    write(clnt_sock, screen_buffer, screen_buffer_size * sizeof(uint8_t));
    do
    {
        read(clnt_sock, &screen_buffer_ans, sizeof(uint8_t));
        usleep(1);
        wait++;
    } while (screen_buffer_ans == 0 || wait > WAIT_TIMES);
    wait = 0;
    write(clnt_sock, obj_buffer, obj_buffer_size * sizeof(PIC_OBJ));
    do
    {
        read(clnt_sock, &obj_buffer_ans, sizeof(uint8_t));
        usleep(1);
    } while (obj_buffer_ans == 0 || wait > WAIT_TIMES);
    if (wait > WAIT_TIMES)
        return -1;
    return 0;
}