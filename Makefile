CC = g++
SRC_DIR = src
CFLAGS = -I include -Wall -Wextra
all: run

run: $(SRC_DIR)/main.cpp $(SRC_DIR)/other.cpp $(SRC_DIR)/equation.cpp $(SRC_DIR)/testing.cpp
	 $(CC) $(CFLAGS) $^ -o auf
	 @./auf

run_test: $(SRC_DIR)/main.cpp $(SRC_DIR)/other.cpp $(SRC_DIR)/equation.cpp $(SRC_DIR)/testing.cpp
		  $(CC) -D TESTING $(CFLAGS) $^ -o auf
		  @./auf