//Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
#include <stdio.h>

void productExceptSelf(int nums[], int n, int answer[]) {
    answer[0] = 1;
    for (int i = 1; i < n; i++)
        answer[i] = answer[i - 1] * nums[i - 1];

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }
}

int main(void) {
    int tests[][5] = {
        {1, 2, 3, 4, 0},
        {-1, 1, 0, -3, 3},
        {0, 0, 0, 0, 0},
    };
    int sizes[] = {4, 5, 4};

    for (int t = 0; t < 3; t++) {
        int n = sizes[t];
        int answer[5];
        productExceptSelf(tests[t], n, answer);

        for (int i = 0; i < n; i++) {
            printf("%d", answer[i]);
            if (i < n - 1) printf(", ");
        }
        printf("\n");
    }
    return 0;
}