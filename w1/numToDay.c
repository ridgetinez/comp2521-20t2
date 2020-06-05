/* Start everything from scratch so everyone's fine with writing C files from scratch! */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
 * numToDay.c
 * 
 * Take in the day 'number' as a command line argument and output the string representation.
 * 
 * Example:
 *      > ./numToDay 2
 *      "Tue"
 * 
 * Note to self: demonstrate returning pointers that were on the stack!
 *
 */

char *numToDay(int n)
{
	assert(0 <= n && n <= 6);
    char *days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	return days[n];
}

int main(int argc, char** argv) {
    printf("%s\n", numToDay(atoi(argv[1])));
}