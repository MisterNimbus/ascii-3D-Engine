.PHONY: all clean run dir

# Compiler Settings
COMPILER    := g++
FLAGS       := -std=c++11 -Wall -Wextra -ggdb

# Folder Hierarchy
SOURCE_DIR  := src
BINARY_DIR  := bin
OBJECT_DIR  := bin/obj
INCLUDE_DIR := src/include
LIBRARY_DIR  := lib

LIBRARIES 		:=
EXECUTABLE_NAME := main.out

# Files
SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.cpp)
HEADER_FILES := $(wildcard $(INCLUDE_DIR)/*.h)
OBJ_FILES    := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJECT_DIR)/%.o,$(SOURCE_FILES))

# Recipes
all: 	dir $(BINARY_DIR)/$(EXECUTABLE_NAME)

run:	clean all
		clear
		./$(BINARY_DIR)/$(EXECUTABLE_NAME)
	
$(BINARY_DIR)/$(EXECUTABLE_NAME):$(OBJ_FILES)
	$(COMPILER) $(OBJ_FILES) -o $(BINARY_DIR)/$(EXECUTABLE_NAME)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(COMPILER) $(FLAGS) -l $(INCLUDE_DIR) -L $(LIBRARY_DIR) -c $< -o $@ $(LIBRARIES)

clean:  
	@-rm -rf $(BINARY_DIR)/*

dir: 
	@mkdir -p $(OBJECT_DIR)