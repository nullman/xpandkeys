.RECIPEPREFIX = >

.PHONY: all clean test

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
TEST_DIR := test

TARGET_FILE := $(BIN_DIR)/xpandkeys
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

CPPFLAGS := -Iinclude -MMD -MP # -I is a preprocessor flag, not a compiler flag
CFLAGS   := -Wall              # some warnings about bad code
LDFLAGS  := -Llib              # -L is a linker flag
LDLIBS   := -lm                # Left empty if no libs are needed

all: $(TARGET_FILE)

$(BIN_DIR) $(OBJ_DIR):
> mkdir -p $@

$(TARGET_FILE): $(OBJ_FILES) | $(BIN_DIR)
> $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
> $(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
> @$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ_FILES:.o=.d)

test: all
> ls
