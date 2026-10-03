//Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than ⌊n / 2⌋ times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.
#include <stdio.h>

int majorityElement(int nums[], int n) {
    if (n <= 0) return -1;

    /* Phase 1: Boyer-Moore voting to find a candidate */
    int candidate = nums[0];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    /* Phase 2: verify the candidate actually appears > n/2 times */
    int freq = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == candidate) freq++;

    return (freq > n / 2) ? candidate : -1;
}

int main(void) {
    int tests[][6] = {
        {3, 2, 3, 0, 0, 0},       /* n=5 -> 3 appears 3 times (>2)   */
        {2, 2, 1, 1, 1, 2},       /* n=6 -> 1 appears 3 times (not >3)*/
        {1, 2, 3, 4, 5, 0},       /* n=5 -> no majority               */
    };
    int sizes[] = {3, 6, 5};

    for (int t = 0; t < 3; t++) {
        printf("Array size %d -> majority: %d\n",
               sizes[t], majorityElement(tests[t], sizes[t]));
    }
    return 0;
}