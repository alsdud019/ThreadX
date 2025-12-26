CC = gcc
CFLAGS = -I./threadx/common/inc \
         -I./threadx/ports/inc \
         -I./src \
         -O2 -g -pthread

TX_COMMON = $(wildcard threadx/common/src/*.c)


TX_PORT = $(wildcard threadx/ports/src/*.c)

APP = $(wildcard app/*.c)

SRCS = $(TX_COMMON) $(TX_PORT) $(APP)
OBJS = $(SRCS:.c=.o)

all: MQdemo

MQdemo: $(OBJS)
	$(CC) -o MQdemo $(OBJS) -pthread

clean:
	rm -f $(OBJS) MQdemo