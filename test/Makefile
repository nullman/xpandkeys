.RECIPEPREFIX = >

SRC_DIR := ../src
TST_DIR := src
OBJ_DIR := obj
BIN_DIR := ../bin

TARGET_FILE := $(BIN_DIR)/run_tests
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))
TST_SRC_FILES := $(wildcard $(TST_DIR)/*.c)
TST_OBJ_FILES := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(TST_SRC_FILES)))

DEPS := $(OBJ_FILES:.o=.d)
TST_DEPS := $(TST_OBJ_FILES:.o=.d)

CPPFLAGS := -MMD -MP
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm

.PHONY: all test clean

all: test

test: $(TARGET_FILE)

$(BIN_DIR) $(OBJ_DIR):
> @mkdir -p $@

$(TARGET_FILE): $(OBJ_FILES) $(TST_OBJ_FILES) | $(BIN_DIR)
> $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
> $(BIN_DIR)/run_tests

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
> $(CC) $(CPPFLAGS) $(CFLAGS) -I$(SRC_DIR) -I$(TST_DIR) -DTEST=1 -c $< -o $@

$(OBJ_DIR)/%.o: $(TST_DIR)/%.c | $(OBJ_DIR)
> $(CC) $(CPPFLAGS) $(CFLAGS) -I$(SRC_DIR) -I$(TST_DIR) -DTEST=1 -c $< -o $@

clean:
> @$(RM) -rv $(BIN_DIR) $(OBJ_DIR) > /dev/null

-include $(DEPS) $(TST_DEPS)
