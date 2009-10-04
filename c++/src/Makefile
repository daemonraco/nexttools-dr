include header.mk
#
SOURCES	= ${SRC_DIR}/DRObject.dr.cpp\
		${SRC_DIR}/DRException.dr.cpp\
		${SRC_DIR}/Log.dr.cpp\
		${SRC_DIR}/options/MultivalueOption.dr.cpp\
		${SRC_DIR}/options/Option.dr.cpp\
		${SRC_DIR}/Options.dr.cpp\
		${SRC_DIR}/Tools.dr.cpp\
		${SRC_DIR}/options/ValueOption.dr.cpp
#
OBJECTS	= ${OBJ_DIR}/DRObject.dr.o\
		${OBJ_DIR}/DRException.dr.o\
		${OBJ_DIR}/Log.dr.o\
		${OBJ_DIR}/MultivalueOption.dr.o\
		${OBJ_DIR}/Option.dr.o\
		${OBJ_DIR}/Options.dr.o\
		${OBJ_DIR}/Tools.dr.o\
		${OBJ_DIR}/ValueOption.dr.o
#
DIRECTORIES	= $(OBJ_DIR) $(BIN_DIR)
#
###
all: dirs $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(BFLAGS) -o $(BIN_DIR)/$(TARGET)
	@if true; then\
	 	ln -sf $(TARGET) $(BIN_DIR)/${shell echo $(TARGET)|cut -d'.' -f1-2};\
	 	ln -sf $(TARGET) $(BIN_DIR)/${shell echo $(TARGET)|cut -d'.' -f1-3};\
	 	ln -sf $(TARGET) $(BIN_DIR)/${shell echo $(TARGET)|cut -d'.' -f1-4};\
	 fi;
#
###
dirs:
	@mkdir -p $(DIRECTORIES);
#
###
${OBJ_DIR}/DRObject.dr.o: ${SRC_DIR}/DRObject.dr.h ${SRC_DIR}/DRObject.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/DRObject.dr.cpp
#
###
${OBJ_DIR}/DRException.dr.o: ${SRC_DIR}/DRException.dr.h ${SRC_DIR}/DRException.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/DRException.dr.cpp
#
###
${OBJ_DIR}/Log.dr.o: ${SRC_DIR}/Log.dr.h ${SRC_DIR}/Log.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/Log.dr.cpp
#
###
${OBJ_DIR}/MultivalueOption.dr.o: ${SRC_DIR}/options/MultivalueOption.dr.h ${SRC_DIR}/options/MultivalueOption.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/options/MultivalueOption.dr.cpp
#
###
${OBJ_DIR}/Option.dr.o: ${SRC_DIR}/options/Option.dr.h ${SRC_DIR}/options/Option.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/options/Option.dr.cpp
#
###
${OBJ_DIR}/Options.dr.o: ${SRC_DIR}/Options.dr.h ${SRC_DIR}/Options.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/Options.dr.cpp
#
###
${OBJ_DIR}/Tools.dr.o: ${SRC_DIR}/Tools.dr.h ${SRC_DIR}/Tools.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/Tools.dr.cpp
#
###
${OBJ_DIR}/ValueOption.dr.o: ${SRC_DIR}/options/ValueOption.dr.h ${SRC_DIR}/options/ValueOption.dr.cpp
	$(OBJ_COMPILE_CMD) ${SRC_DIR}/options/ValueOption.dr.cpp
#
###
test:
	@echo -e "\tTARGET_NAME: $(TARGET_NAME)";\
	 echo -e "\tVERSION:     $(VERSION)";\
	 echo -e "\tONLINE_DOCS: $(ONLINE_DOCS)";\
	 echo -e "\tTARGET:      $(TARGET)";\
	 echo -e "\tCOMPILER:    $(COMPILER)";\
	 echo -e "\tOFLAGS:      $(OFLAGS)";\
	 echo -e "\tBFLAGS:      $(BFLAGS)";\
	 echo -e "\tSRC_DIR:     $(SRC_DIR)";\
	 echo -e "\tOBJ_DIR:     $(OBJ_DIR)";\
	 echo -e "\tBIN_DIR:     $(BIN_DIR)";\
	 echo -e "\tOBJ_COMPILE_CMD: $(OBJ_COMPILE_CMD)";
#
###
clean:
	@rm -f $(OBJECTS) 2>&1 | awk '{print "\t"$$0}';				\
	 rm -f $(BIN_DIR)/* 2>&1 | awk '{print "\t"$$0}';
#
###
clear: clean
