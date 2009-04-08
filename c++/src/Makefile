#
SOURCES	= $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS	= $(SOURCES,.cpp=.o)

#

all: $(OBJECTS)
	@echo $(OBJECTS);
	$(COMPILER) $(OBJECTS) $(BFLAGS) $(TARGET)

.o.cpp:
	$(COMPILER) $(OFLAGS) -c $< -o $@

clean:

clear: clean

.PHONY: all clean clear

