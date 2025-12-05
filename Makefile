# ---------- CONFIG ----------
CXX = g++
CC  = gcc

# Release flags
CXXFLAGS = -std=c++17 -O2 -Wall -Iinclude
CFLAGS   = -O2 -Wall -Iinclude

# Debug flags
DEBUG_FLAGS = -g -O0 -DDEBUG -DRAYLIB_DEBUG

SRC_CPP = src/main.cpp
SRC_C   = lib/flecs/flecs.c

OBJ_CPP = $(SRC_CPP:.cpp=.o)
OBJ_C   = $(SRC_C:.c=.o)

TARGET = game

# Linux system libs required by Raylib
SYSTEM_LIBS = -lGL -lm -lpthread -ldl -lrt -lX11

# Local Raylib static library
RAYLIB_LOCAL = lib/libraylib.a

# ---------- RULES ----------
all: $(TARGET)

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: CFLAGS   += $(DEBUG_FLAGS)
debug: clean all

$(TARGET): $(OBJ_CPP) $(OBJ_C)
	$(CXX) $(OBJ_CPP) $(OBJ_C) $(RAYLIB_LOCAL) -o $(TARGET) $(SYSTEM_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ_CPP) $(OBJ_C)

run: all
	./$(TARGET)

run-debug: debug
	./$(TARGET)
