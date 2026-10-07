//Write a program to take an integer array arr and an integer k as inputs. Print the maximum sum of all the subarrays of size k.#include <stdio.h>

void maxSumSubarray(int arr[], int n, int k) {
    if (n < k) {
        printf("-1\n");
        return;
    }

    int windowSum = 0;
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    int maxSum = windowSum;

    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum)
            maxSum = windowSum;
    }

    printf("%d\n", maxSum);
}

int main(void) {
    int tests[][6] = {
        {1, 4, 2, 10, 2, 0},
        {2, 1, 5, 1, 3, 2},
        {3, -1, 4, -2, 5, 0},
    };
    int sizes[] = {5, 5, 5};
    int ks[] = {3, 3, 4};

    for (int t = 0; t < 3; t++) {
        int n = sizes[t];
        printf("k=%d -> ", ks[t]);
        maxSumSubarray(tests[t], n, ks[t]);
    }
    return 0;
}