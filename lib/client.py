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
    uint16_t start;
    uint16_t show;
    uint16_t v;
    uint16_t cur_x;
    uint16_t cur_y;
'''
class PIC_OBJ(object):
    def __b2i__(self,byte):
        self.screen = byte[:115200]
        b = byte[115200:]
        self.pixel = b[:400]
        b = b[400:]
        res = struct.unpack('H',b)
        self.start_x = res[0]
        self.start_y = res[1]
        self.end_x = res[2]
        self.end_y = res[3]
        self.speed = res[4]
        self.start = res[5]
        self.show = res[6]
        self.v = res[7]
        self.cur_x = res[8]
        self.cur_y = res[9]

    def __init__(self,byte):
        self.screen = b'\0'
        self.pixel = b'\0'
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
        self.__b2i__(byte)




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
        if len(buffer) == 115200:
            s.send(b'\1')
        if len(buffer) == 115305:
            s.send(b'\1')
    else:
        break
data = b''.join(buffer)