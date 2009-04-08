TARGET		= nexttools
VERSION		= 0.1b

COMPILER	= gcc
OFLAGS		= -I. -DVERSION="$(VERSION)" -DTARGET="$(TARGET)"
BFLAGS		= -shared

SRC_DIR		= $(PWD)/src
OBJ_DIR		= $(SRC_DIR)/.obj
BIN_DIR		= $(SRC_DIR)/.bin

all:
	@mkdir -vp $(OBJ_DIR) $(BIN_DIR);
	$(MAKE) -C src

clean:
	$(MAKE) -C src clean

clear: clean

.PHONY: all clean clear

