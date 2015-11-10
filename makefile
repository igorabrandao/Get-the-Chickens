#
# Makefile build 'Get the Chickens' using Make
#

SOURCES = $(wildcard src/*.cpp)

CC      = g++
CFLAGS  = -c -g -Wall -std=c++11

INC_DIR = ./include
BIN_DIR = ./bin
APP     = $(BIN_DIR)/app
LIB_DIR = 
LIBS = \
	-lsfml-graphics         \
	-lsfml-audio 	        \
	-lsfml-window           \
	-lsfml-system

OBJECTS = $(SOURCES:.cpp=.o)

$(APP): $(OBJECTS) 
	$(CC) -o $@ $(OBJECTS) $(LIBS)

.cpp.o:
	$(CC) $< -o $@ $(CFLAGS) -I$(INC_DIR)

.PHONY: clean

clean:
	rm $(APP) $(OBJECTS)

exe:
	$(APP)