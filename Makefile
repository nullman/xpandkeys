.RECIPEPREFIX = >

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
TST_DIR := test

TARGET_FILE := $(BIN_DIR)/xpandkeys
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm

.PHONY: all clean test

all: build

build: $(TARGET_FILE)

$(BIN_DIR) $(OBJ_DIR):
> @mkdir -p $@

$(TARGET_FILE): $(OBJ_FILES) | $(BIN_DIR)
> $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
> $(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
> @$(RM) -rv $(BIN_DIR) $(OBJ_DIR) > /dev/null

-include $(OBJ_FILES:.o=.d)

test:
> cd test && make
