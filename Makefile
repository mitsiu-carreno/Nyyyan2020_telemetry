# Determine the platform
PLAT_NAME := $(shell uname -s)

# Compiler
ifeq ($(PLAT_NAME), Darwin)
  CC=clang++ -arch x86_64
else
  CC=g++
endif

# Project structure

SRC_DIR     := src
BUILD_DIR   := build
EXEC_DIR    := bin
INCLUDE_DIR := include

# Executable
EXEC_TARGET_NAME  := nyyyan2020_telemetry
EXEC_FULL_PATH    := $(EXEC_DIR)/$(EXEC_TARGET_NAME)

# Code properties
SRC_EXT               := cpp
# Find all .cpp
SRC_FULL_PATH_LIST    := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
# Based on SRC_FULL_PATH_LIST create the list of *.o files
O_FILE_FULL_PATH_LIST := $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(SRC_FULL_PATH_LIST:.$(SRC_EXT)=.o))
# Based on O_FILE_FULL_PATH_LIST remove the *.o file (just leave the directory structure)
BUILD_DIRECTORY_LIST  := $(foreach O_FILE, $(O_FILE_FULL_PATH_LIST), $(subst $(notdir $(O_FILE)), , $(O_FILE)))
# Remove duplicates
BUILD_DIRECTORY_LIST  := $(sort $(BUILD_DIRECTORY_LIST))

# Find all directories containing .hpp and .h files
HEADER_DIRECTORY_LIST := $(shell find $(INCLUDE_DIR) \( -name '*.hpp' -o -name '*.h' \) -exec dirname {} \; | sort | uniq )
# Prefix -I to all directories containing .hpp and .h files
INCLUDE_LIST          := $(patsubst $(INCLUDE_DIR)%, -I $(INCLUDE_DIR)%, $(HEADER_DIRECTORY_LIST))
INCLUDE_EXTRAS= -I/usr/include/python3.10

# Compile flags
CFLAGS= -c -std=c++1z -Wall -Werror -g
#CFLAGS= -c -std=c++1z 
# Linker flags
LFLAGS= -lpthread -lpython3.10

$(EXEC_DIR): $(O_FILE_FULL_PATH_LIST)
	@echo ""
	@echo "---------------REMEMBER---------------"
	@echo "you can go 'make port=\"8081\"'"
	@echo "                  OR                  "
	@echo "./$(EXEC_FULL_PATH) 8081"
	@echo ""
	@mkdir -p $(EXEC_DIR)
	@echo "Linking..."
	@echo "   $(CC) $^ -o $(EXEC_FULL_PATH) $(LFLAGS)"; $(CC) $^ -o $(EXEC_FULL_PATH) $(LFLAGS);
	@echo "Build complete, executing..."
	@echo ""
	./$(EXEC_FULL_PATH) $(port)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(BUILD_DIRECTORY_LIST)
	@echo "Compiling $<..."
	@echo "$(CC) $(CFLAGS) $(INCLUDE_EXTRAS) $(INCLUDE_LIST) $< -o $@"; $(CC) $(CFLAGS) $(INCLUDE_EXTRAS) $(INCLUDE_LIST) $< -o $@

run:
	@echo ""
	@echo "---------------REMEMBER---------------"
	@echo "you can go 'make port=\"8081\"'"
	@echo "                  OR                  "
	@echo "./$(EXEC_FULL_PATH) 8081"
	@echo ""
	./$(EXEC_FULL_PATH) $(port)

debug:	
	@echo "SRC_FULL_PATH_LIST $(SRC_FULL_PATH_LIST)"
	@echo "O_FILE_FULL_PATH_LIST $(O_FILE_FULL_PATH_LIST)"
	@echo "BUILD_DIRECTORY_LIST $(BUILD_DIRECTORY_LIST)"
	@echo ""
	@echo "HEADER_DIRECTORY_LIST $(HEADER_DIRECTORY_LIST)"
	@echo "INCLUDE_LIST $(INCLUDE_LIST)"

clean:
	@echo "Cleaning $(EXEC_FULL_PATH) ..."; $(RM) -r $(EXEC_FULL_PATH)

hardclean:
	@echo "Cleaning $(EXEC_FULL_PATH) and $(BUILD_DIR)/* ..."; $(RM) -r $(BUILD_DIR)/* $(EXEC_FULL_PATH)

.PHONY: clean
