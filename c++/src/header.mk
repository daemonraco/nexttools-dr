#
TARGET_NAME	= nexttools
VERSION		= 0.1.0
ONLINE_DOCS	= http://docs.daemonraco.com/NextTools/c++
#
TARGET		= lib$(TARGET_NAME).so.$(VERSION)
#
COMPILER		= g++
OFLAGS		= -I. -Ioptions -DVERSION="$(VERSION)" -DTARGET="$(TARGET)" -DONLINE_DOCS="$(ONLINE_DOCS)"
BFLAGS		= -shared
#
SRC_DIR		= $(PWD)
OBJ_DIR		= $(SRC_DIR)/.obj
BIN_DIR		= $(SRC_DIR)/.bin
#
OBJ_COMPILE_CMD	= $(COMPILER) $(OFLAGS) -o $@ -c
