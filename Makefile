.RECIPEPREFIX = >

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
TST_DIR := test

TARGET_FILE := $(BIN_DIR)/xpandkeys
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))

DEPS := $(OBJ_FILES:.o=.d)

CPPFLAGS := -MMD -MP
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm

.PHONY: all build test clean

all: build

build: $(TARGET_FILE)

$(BIN_DIR) $(OBJ_DIR):
> @mkdir -p $@

$(TARGET_FILE): $(OBJ_FILES) | $(BIN_DIR)
> $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
> $(CC) $(CPPFLAGS) $(CFLAGS) -I$(SRC_DIR) -DTEST=0 -c $< -o $@

test:
> pushd test && ( make ; popd )

clean:
> @$(RM) -rv $(BIN_DIR) $(OBJ_DIR) > /dev/null
> pushd test && ( make clean ; popd )

-include $(DEPS)
