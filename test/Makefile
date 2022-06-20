.RECIPEPREFIX = >

SRC_DIR := ../src
OBJ_DIR := ../obj
BIN_DIR := ../bin
TST_DIR := .

TARGET_FILE := $(BIN_DIR)/run-tests
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
TST_FILES := $(wildcard $(TST_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) $(patsubst ../$(TST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TST_FILES))

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm

.PHONY: all clean test

all: test

test: $(TARGET_FILE)
> $(TARGET_FILE)

$(BIN_DIR) $(OBJ_DIR):
> @mkdir -p $@

$(TARGET_FILE): $(OBJ_FILES) | $(BIN_DIR)
> $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(TST_DIR)/%.c | $(OBJ_DIR)
> $(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
> @$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ_FILES:.o=.d)
