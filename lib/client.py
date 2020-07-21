# 导入socket库:
import socket
import struct
'''
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
'''
class PIC_OBJ(object):
    def __b2i__(self,bytes):
        struct.unpack('H',)
    def __init__(self,bytes):
        self.start_x = 0
        self.start_y = 0
        self.end_x = 0
        self.end_y = 0
        self.speed = 0
        self.start = 0
        self.show = 0
        self.v = 0
        self.cur_x = 0
        self.cur_y = 0
        self.__b2i__(bytes)




# 创建一个socket:
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 建立连接:
s.connect(("127.0.0.1", 8087))
buffer = []
while True:
    # 每次最多接收1k字节:
    d = s.recv(1024)
    if d:
        buffer.append(d)
    else:
        break
data = b''.join(buffer)