#
SOURCES	= ${SRC_DIR}/DRObject.dr.cpp\
		${SRC_DIR}/Log.dr.cpp\
		${SRC_DIR}/MultivalueOption.dr.cpp\
		${SRC_DIR}/Option.dr.cpp\
		${SRC_DIR}/Options.dr.cpp\
		${SRC_DIR}/Tools.dr.cpp\
		${SRC_DIR}/ValueOption.dr.cpp
OBJECTS	= $(SOURCES:$(SRC_DIR)/%.dr.cpp=$(OBJ_DIR)/%.dr.o)
#
all: $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(BFLAGS) -o $(BIN_DIR)/$(TARGET)

${OBJ_DIR}/DRObject.dr.o: ${SRC_DIR}/DRObject.dr.h ${SRC_DIR}/DRObject.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/DRObject.dr.cpp

${OBJ_DIR}/Log.dr.o: ${SRC_DIR}/Log.dr.h ${SRC_DIR}/Log.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/Log.dr.cpp

${OBJ_DIR}/MultivalueOption.dr.o: ${SRC_DIR}/MultivalueOption.dr.h ${SRC_DIR}/MultivalueOption.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/MultivalueOption.dr.cpp

${OBJ_DIR}/Option.dr.o: ${SRC_DIR}/Option.dr.h ${SRC_DIR}/Options.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/Option.dr.cpp

${OBJ_DIR}/Options.dr.o: ${SRC_DIR}/Options.dr.h ${SRC_DIR}/Options.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/Options.dr.cpp

${OBJ_DIR}/Tools.dr.o: ${SRC_DIR}/Tools.dr.h ${SRC_DIR}/Tools.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/Tools.dr.cpp

${OBJ_DIR}/ValueOption.dr.o: ${SRC_DIR}/ValueOption.dr.h ${SRC_DIR}/ValueOption.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/ValueOption.dr.cpp

clean:
	@rm -fv $(OBJECTS) 2>&1 | awk '{print "\t"$$0}';				\
	 rm -fv $(BIN_DIR)/* 2>&1 | awk '{print "\t"$$0}';

clear: clean

.PHONY: all clean clear

