CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
EXEC = $(BIN_DIR)/main

$(EXEC): $(OBJS)
    @mkdir -p $(BIN_DIR)
    $(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(wildcard $(SRC_DIR)/*.h)
    @mkdir -p $(OBJ_DIR)
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: clean
