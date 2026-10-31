//Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.
#include <stdio.h>

enum Status {
    SUCCESS,
    FAILURE,
    TIMEOUT
};

int main(void)
{
    enum Status statuses[] = { SUCCESS, FAILURE, TIMEOUT };
    int i;
    int n = sizeof(statuses) / sizeof(statuses[0]);

    for (i = 0; i < n; i++) {
        switch (statuses[i]) {
            case SUCCESS:
                printf("Operation completed successfully.\n");
                break;
            case FAILURE:
                printf("Operation failed. Please try again.\n");
                break;
            case TIMEOUT:
                printf("Operation timed out. Check your connection.\n");
                break;
            default:
                printf("Unknown status.\n");
                break;
        }
    }

    return 0;
}
