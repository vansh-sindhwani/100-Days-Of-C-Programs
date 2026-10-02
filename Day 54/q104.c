//Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.
#include <stdio.h>
#include <math.h>

int main() {
    long long n;
    scanf("%lld", &n);

    // total sum from 1 to n
    long long total = n * (n + 1) / 2;

    // We need x such that x*(x+1)/2 == total - x*(x-1)/2
    // which simplifies to: x*x == total
    // so x must be sqrt(total)

    long long x = (long long)sqrt(total);

    if (x * x == total) {
        printf("%lld\n", x);
    } else {
        printf("-1\n");
    }

    return 0;
}