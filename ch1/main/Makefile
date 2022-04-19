ifeq ($(RELEASE), 1)
DBG_FLAGS = -O2
else
DBG_FLAGS = -g -O0 -DDEBUG
endif

PWD = $(shell pwd)

INC_DIRS = -I$(PWD)/../src

OBJS = $(SRCS:%.c=%.o)

TARGET = main_stack

SRC_DIR = $(PWD)/../src

SRC_OBJS = $(shell find $(SRC_DIR) -name '*.o')

all:	$(TARGET)

main_stack:		main_stack.o
	@echo "$@"
	@echo "$(SRC_OBJS)"
	$(CC) -o $@ main_stack.o $(SRC_OBJS)

.c.o:
	@echo "==========================================="
	@echo "========= Compiling Stack Program ========="
	@echo "==========================================="
	$(CC) $(DBG_FLAGS) -c $< -o $@ $(INC_DIRS)

clean:
	rm -rf *.o
	rm -rf $(TARGET)
