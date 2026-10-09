//Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output
#include <stdio.h>

void firstNegativeInWindows(int arr[], int n, int k) {
    if (n < k || k <= 0) {
        printf("\n");
        return;
    }

    for (int i = 0; i <= n - k; i++) {
        int found = 0;
        for (int j = i; j < i + k; j++) {
            if (arr[j] < 0) {
                printf("%d", arr[j]);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("0");
        if (i < n - k) printf(" ");
    }
    printf("\n");
}

int main(void) {
    int tests[][7] = {
        {12, -1, -7, 8, -15, 30, 16},
        {2, 3, 4, -1, -5, 2, 6},
        {1, 2, 3, 4, 5, 6, 0},
    };
    int sizes[] = {7, 6, 7};
    int ks[] = {3, 3, 4};

    for (int t = 0; t < 3; t++) {
        printf("k=%d -> ", ks[t]);
        firstNegativeInWindows(tests[t], sizes[t], ks[t]);
    }
    return 0;
}