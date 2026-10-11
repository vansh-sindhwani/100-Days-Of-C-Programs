//Write a program to take an integer array arr and an integer k as inputs. The task is to find the kth smallest element in the array. Print the kth smallest element as output.
#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

void kthSmallest(int arr[], int n, int k) {
    if (k < 1 || k > n) {
        printf("-1\n");
        return;
    }

    int low = 0, high = n - 1;
    while (low <= high) {
        int p = partition(arr, low, high);
        if (p == k - 1) {
            printf("%d\n", arr[p]);
            return;
        } else if (p < k - 1)
            low = p + 1;
        else
            high = p - 1;
    }
}

int main(void) {
    int tests[][7] = {
        {7, 10, 4, 3, 20, 15, 0},
        {12, 3, 5, 7, 19, 0, 0},
        {-1, -2, -3, 0, 5, 0, 0},
    };
    int sizes[] = {6, 5, 4};
    int ks[] = {3, 2, 1};

    for (int t = 0; t < 3; t++) {
        printf("k=%d -> ", ks[t]);
        kthSmallest(tests[t], sizes[t], ks[t]);
    }
    return 0;
}