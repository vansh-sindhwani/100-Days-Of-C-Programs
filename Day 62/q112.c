//Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.
#include <stdio.h>

void kadane(int arr[], int n) {
    if (n == 0) { printf("0\n"); return; }

    int max_so_far = arr[0];
    int current_max = arr[0];

    for (int i = 1; i < n; i++) {
        current_max = (current_max + arr[i] > arr[i]) ? current_max + arr[i] : arr[i];
        max_so_far = (max_so_far > current_max) ? max_so_far : current_max;
    }

    printf("%d\n", max_so_far);
}

int main(void) {
    int tests[][8] = {
        {-2, 1, -3, 4, -1, 2, 1, -5},
        {5, 4, -1, 7, 8, 0, 0, 0},
        {-1, -2, -3, -4, 0, 0, 0, 0},
        {1, -2, 3, -4, 5, 0, 0, 0},
    };
    int sizes[] = {8, 5, 4, 5};

    for (int t = 0; t < 4; t++) {
        kadane(tests[t], sizes[t]);
    }
    return 0;
}