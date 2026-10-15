//Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number
#include <stdio.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 0)
        return 1;

    long long expectedSum = (long long)n * (n + 1) / 2;
    long long actualSum = 0;

    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1)
            return 1;
        actualSum += value;
    }

    printf("%lld\n", expectedSum - actualSum);
    return 0;
}