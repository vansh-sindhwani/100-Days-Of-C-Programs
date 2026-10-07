//Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.
#include <stdio.h>

void maxInWindows(int arr[], int n, int k) {
    if (n < k || k <= 0) {
        printf("\n");
        return;
    }

    for (int i = 0; i <= n - k; i++) {
        int mx = arr[i];
        for (int j = i + 1; j < i + k; j++)
            if (arr[j] > mx)
                mx = arr[j];

        printf("%d", mx);
        if (i < n - k) printf(" ");
    }
    printf("\n");
}

int main(void) {
    int tests[][7] = {
        {1, 3, -1, -3, 5, 3, 6},
        {2, 9, 3, 8, 1, 7, 4},
        {4, 3, 2, 1, 0, 5, 6},
    };
    int sizes[] = {7, 6, 7};
    int ks[] = {3, 3, 4};

    for (int t = 0; t < 3; t++) {
        printf("k=%d -> ", ks[t]);
        maxInWindows(tests[t], sizes[t], ks[t]);
    }
    return 0;