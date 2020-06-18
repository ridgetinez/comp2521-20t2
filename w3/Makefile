CC=gcc
CFLAGS=-Wall -Werror -g
OBJS=Tree.o testTree.o
BINS=testTree.out pragma

all : $(BINS)

testTree.out : $(OBJS)
	$(CC) -o testTree.out $(OBJS)

Tree.o : Tree.c Tree.h
testTree.o : TestTree.c Tree.h

pragma: pragma.c
	$(CC) $(CFLAGS) -o pragma pragma.c

.PHONY: clean
clean :
	rm -fr $(BINS) $(OBJS)