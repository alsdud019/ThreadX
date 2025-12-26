#include "tx_api.h"


void tx_application_define(void *first_unused_memory)
{
    
    //메모리 블럭 풀 할당 함수 호출
    app_memory_pool_init();
    //메세지 큐 생성 
    app_massageQ_init();
    //스레드 생성 함수 호출
    app_thread_init(first_unused_memory);


}

int main()
{
    tx_kernel_enter();
    return 0;
}