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
    if (n == 1 || n == 2) return 1;
    int nth_fib = 2, prev_fib = 1, curr_fib = 1;
    while (nth_fib < n) {
        int tmp = prev_fib;
        prev_fib = curr_fib;
        curr_fib = tmp + curr_fib;
        nth_fib++;
    }
    return curr_fib;
}

// Q2. Write an O(1) algorithm to compute the nth fibonacci number that'll fit in an int.
int fib1(int n)
{
    // A: Trick question! ints can only hold so much, in fact we can fit ~45th fibonacci number without overflow.
    //    So we can create an array that holds the first 45 and return -1 if n < 0 || n >= 45
    return 0;
}

// Q3. Compute x^n and return
// Can anyone see what might be wrong with the return type?
// Todo: write an O(logN) version
// Note to me: Good to draw why our solution is O(logN)
int pow_nat(int x, unsigned int n)
{
    // x^(2*j) = x^j * x^j
    // x^(2*j+1) = x^j * x^j * x^1
    if (n == 0) return 1;
    if (n == 1) return x;
    int it_is_odd = n % 2;
    int res = pow_nat(x, n/2);    
    // x^(2*j+1) = x^j * x^j * x^1
    if (it_is_odd) return res * res * x;
    else return res * res;
}

int main(void)
{
    // The bad fib! exponential
    for (int i = 1; i < 10; i++) {
        printf("fib(%d): %d | ", i, fib(i));
    }
    printf("\n");
    
    // The good fib! O(n)
    for (int i = 1; i < 100; i++) {
        printf("fib(%d): %d | ", i, fibn(i));
    }
    printf("\n");

    printf("%d\n", pow_nat(3,10)); // should be 59049
}