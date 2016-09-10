CC=g++
OUTPUT=Gas.bin
CFLAGS=-Wall -std=c++11 -o $(OUTPUT)

all: build run clean

build:
	$(CC) $(CFLAGS) utils/MessageList.cpp controller.cpp modules/module.cpp main.cpp

run: build
	./Gas.bin

clean:
	rm *.bin
