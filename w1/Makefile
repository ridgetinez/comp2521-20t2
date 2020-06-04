# Why makefiles?
# (1) Saves you the tedium of writing these lengthy commands in the correct order.
# (2) At a certain point, some projects are too large to compile by hand.
# (3) Standardised "language" that everyone can learn and bring with them project to project

CC=gcc
CFLAGS=-Wall -Werror

# Generating executables that depend on other targets like list.o
test: testList.c List.o
	$(CC) -o testList testList.c List.o


# Generating intermediary object files can be automatically inferred by Make :)
List.o: List.c List.h
	$(CC) $(CFLAGS) -c List.c List.h

# Phony targets are targets that don't generate any new files / artifacts
.PHONY: clean
clean:
	rm -f *.o *.gch testList