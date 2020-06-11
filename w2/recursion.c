#include <stdio.h>
#include <assert.h>

// Q0. What's the time complexity of fib? What's this in BigO notation?
int fib(int n)
{
    assert(n > 0);
    if (n == 1 || n == 2) return 1;
    return fib(n-1) + fib(n-2);
}

// Q1. Write an O(N) algorithm to compute the nth fibonacci number.
int fibn(int n)
{
    return 0;
}

// Q2. Write an O(1) algorithm to compute the nth fibonacci number that'll fit in an int.
int fib1(int n)
{
    // This one is a trick question :)
    return 0;
}

// Q3. Compute x^n and return
// Can anyone see what might be wrong with the return type?
// Todo: write an O(logN) version
// Note to me: Good to draw why our solution is O(logN)
int pow_nat(int x, unsigned int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
       res = res * x;
    return res;
}

int main(void)
{
    // The bad fib!
    for (int i = 1; i < 10; i++) {
        printf("fib(%d): %d | ", i, fib(i));
    }
    printf("\n");
    
    // The good fib!
    for (int i = 1; i < 100; i++) {
        printf("fib(%d): %d | ", i, fibn(i));
    }
    printf("\n");

    printf("%d\n", pow_nat(3,10)); // should be 59049
}