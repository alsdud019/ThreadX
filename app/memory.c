#include "tx_api.h"


typedef struct {
    char string[50];
} payload_t; //문자열을 담는 구조체

#define BLOCK_SIZE (sizeof(payload_t)) //블럭 하나 크기=> 구조체 하나 크기 
#define POOL_SIZE (BLOCK_SIZE*20) //블럭 크기 * 개수 => 총 바이트 수

TX_BLOCK_POOL my_block_pool;
UINT mem_status;
UCHAR pool_start[POOL_SIZE]; //사용자 배열 생성-> 블럭풀로 사용, 안전한 포인터 주소 생성 


void app_memory_pool_init(){
    
    //메모리 블럭 풀 생성(제어 블럭 포인터, 블럭 이름 포인터, 블럭 하나 크기, 블럭 풀 시작주소, 메모리 블록 풀 총 바이트 수)
    mem_status= tx_block_pool_create(&my_block_pool, "my_block_pool",BLOCK_SIZE, pool_start, sizeof(pool_start));
}



