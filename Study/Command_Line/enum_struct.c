#include <stdio.h>

enum PacketType{
    DATA,
    ACK,
    CONTROL
};

struct Packet{
    enum PacketType type;
    int size;
};

void PrintPaketInfo(struct Packet p){
    printf("Packet size:%d\n",p.size);
    switch (p.type)
    {
    case DATA:
        printf("Packet type: DATA\n");
        break;
    case ACK:
        printf("Packet type: ACK\n");
        break;
    case CONTROL:
        printf("Packet type: CONTROL\n");
        break;
    default:
        break;
    }
}

int main(){
   struct Packet p1={DATA,10};
   struct Packet p2={ACK,20};
   PrintPaketInfo(p1);
   PrintPaketInfo(p2);
   return 0;

}