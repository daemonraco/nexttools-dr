#
export TARGET_NAME	= nexttools
export VERSION		= 0.1.0
#
export TARGET		= lib$(TARGET_NAME).so.$(VERSION)
#
export COMPILER		= g++
export OFLAGS		= -I. -DVERSION="$(VERSION)" -DTARGET="$(TARGET)"
export BFLAGS		= -shared
#
export SRC_DIR		= $(PWD)/src
export OBJ_DIR		= $(SRC_DIR)/.obj
export BIN_DIR		= $(SRC_DIR)/.bin
#
export OBJ_COMPILE_CMD	= $(COMPILER) $(OFLAGS) -o $$@ -c
#
all:
	@mkdir -vp $(OBJ_DIR) $(BIN_DIR);
	$(MAKE) -C src
	@ln -svf $(TARGET) $(BIN_DIR)/${shell echo $(TARGET)|cut -d'.' -f1-2};	\
	 ln -svf $(TARGET) $(BIN_DIR)/${shell echo $(TARGET)|cut -d'.' -f1-3};	\
	 ln -svf $(TARGET) $(BIN_DIR)/${shell echo $(TARGET)|cut -d'.' -f1-4};

clean:
	$(MAKE) -C src clean

clear: clean

.PHONY: all clean clear

