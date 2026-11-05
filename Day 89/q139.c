//Show that enums store integers by printing assigned values.
#include <stdio.h>

enum Status {
    SUCCESS = 0,
    FAILURE = -1,
    TIMEOUT = 5,
    RETRY
};

int main(void)
{
    enum Status s;

    printf("SUCCESS = %d\n", SUCCESS);
    printf("FAILURE = %d\n", FAILURE);
    printf("TIMEOUT = %d\n", TIMEOUT);
    printf("RETRY   = %d\n", RETRY);

    s = RETRY;
    printf("\ns = RETRY, value of s = %d\n", s);
    printf("sizeof(enum Status) = %zu bytes\n", sizeof(enum Status));

    return 0;
}