CC=g++
OUTPUT=Gas.bin
CFLAGS=-Wall -std=c++11 -o $(OUTPUT) -lpthread

all: build run clean

build:
	$(CC) $(CFLAGS) utils/MessageList.cpp controller.cpp modules/module.cpp modules/SensorModule/SensorModule.cpp modules/errorLoggerModule/errorLoggerModule.cpp main.cpp

run: build
	./Gas.bin

clean:
	rm *.bin
