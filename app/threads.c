#include "tx_api.h"
#include <stdio.h>

#define DEMO_STACK_SIZE 1024

TX_THREAD thread_1;
TX_THREAD thread_2;

void thread_1_entry(ULONG thread_input)
{
    while(1)
    {
	printf("thread 1 running\n");
	tx_thread_sleep(200);
    }
}


void thread_2_entry(ULONG thread_input)
{
    while(1)
    {
	printf("thread 2 running\n");
	tx_thread_sleep(200);
    }
}

void app_thread_init(void *first_unused_memory){
    CHAR *pointer = (CHAR *) first_unused_memory;

    tx_thread_create(&thread_1, "thread 1", thread_1_entry, 1,
          pointer, DEMO_STACK_SIZE, 1, 1, TX_NO_TIME_SLICE, TX_AUTO_START);
    pointer +=DEMO_STACK_SIZE;
    
    tx_thread_create(&thread_2, "thread 2", thread_2_entry, 2,
          pointer, DEMO_STACK_SIZE, 2, 2, TX_NO_TIME_SLICE,TX_AUTO_START);
}