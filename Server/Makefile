
.PHONY: server clean run
CC := g++
CFLAG := -std=c++17 -Wall -Wextra -I./cpp-httplib

# link thư viện socket Windows
LIBS := -lws2_32

server:
	mkdir -p ./build
	$(CC) $(CFLAG) -o ./build/$@ server.cpp $(LIBS)
run:
	./build/server
clean:
	rm -rf ./build

# .PHONY: all server clean run

# CC := g++
# CFLAGS := -std=c++17 -Wall -Wextra -I./cpp-httplib
# LIBS := -lws2_32
# BUILD_DIR := build
# TARGET := $(BUILD_DIR)/server
# SRC := server.cpp

# all: server

# $(TARGET): $(SRC)
# 	mkdir -p $(BUILD_DIR)
# 	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# server: $(TARGET)

# run:
# 	./$(TARGET)

# clean:
# 	rm -rf $(BUILD_DIR)


