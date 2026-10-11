//Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char s[]) {
    if (strlen(s) == 0) return 0;

    int last[256];
    for (int i = 0; i < 256; i++) last[i] = -1;

    int maxLen = 0, left = 0;

    for (int right = 0; right < (int)strlen(s); right++) {
        if (last[(unsigned char)s[right]] >= left)
            left = last[(unsigned char)s[right]] + 1;

        last[(unsigned char)s[right]] = right;

        int curLen = right - left + 1;
        if (curLen > maxLen) maxLen = curLen;
    }

    return maxLen;
}

int main(void) {
    char tests[][15] = {"abcabcbb", "bbbbb", "pwwkew", "abcde"};

    for (int i = 0; i < 4; i++) {
        printf("%s -> %d\n", tests[i], lengthOfLongestSubstring(tests[i]));
    }
    return 0;
}