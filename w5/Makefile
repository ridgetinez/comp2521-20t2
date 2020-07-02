CC=gcc
CFLAGS=-Wall -Werror -g
OBJS=glab.o Graph.o Queue.o Stack.o PQueue.o List.o

glab : $(OBJS)
	$(CC) -o glab $(OBJS)

glab.o : glab.c Graph.h

Graph.o  : Graph.c Graph.h Queue.h Stack.h List.h
Queue.o  : Queue.c Queue.h Item.h
Stack.o  : Stack.c Stack.h Item.h
PQueue.o : PQueue.c PQueue.h Item.h
List.o   : List.c List.h Item.h

clean :
	rm -f glab $(OBJS) core *.dSYM
