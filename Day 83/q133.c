//Create an enum for months and print how many days each month has.
#include <stdio.h>

enum Month {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

int main(void)
{
    const char *names[] = {
        "JANUARY", "FEBRUARY", "MARCH", "APRIL",
        "MAY", "JUNE", "JULY", "AUGUST",
        "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"
    };

    const int days[] = {
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    };

    enum Month m;
    for (m = JANUARY; m <= DECEMBER; m++) {
        printf("%-10s has %d days\n", names[m], days[m]);
    }

    return 0;
}