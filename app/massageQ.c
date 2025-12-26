#include "tx_api.h"

#define MSG_SIZE 16 //큐 안에 메세지 총 개수 

ULONG q_storage[MSG_SIZE];

TX_QUEUE my_queue;
UINT msg_status;

void app_massageQ_init(){
    //메세지 큐 생성(제어 블록 포인터, 큐의 이름 포인터, 각 메세지의 크기(1~16), 메세지 큐 시작 주소, 큐에 사용할 총 바이트 수)
    msg_status=tx_queue_create(&my_queue, "my_queue_name", TX_1_ULONG, q_storage, sizeof(q_storage));
}