# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude

# Source and build folders
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build

# Find all .c files in src/
SRC = $(wildcard $(SRC_DIR)/*.c)
# Replace src/file.c with build/file.o
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Final binary name
TARGET = program

# Default target
all: $(TARGET)

# Link all objects into final binary
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

# Compile each .c into .o inside build/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build folder if missing
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run:
	./program

# Cleanup
clean:
	rm -rf $(OBJ_DIR) $(TARGET)