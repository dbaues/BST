SRC_DIR		:= src
OBJ_DIR		:= ${SRC_DIR}/obj
CC			:= g++

_OBJS		:= main.o bst.o
OBJS		:= ${patsubst %, ${OBJ_DIR}/%, ${_OBJS}}

.PHONY: clean all

all: bst

clean:
	rm ${OBJS} bst

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	${CC} -c -o $@ $<

bst: ${OBJS}
	${CC} -o $@ $^
