// make reverse_substring && ./reverse_substring

#include "base.h"
#include <string.h>

/*
Aufgabe:

Ein String s, ein Startindex und eine Länge werden übergeben.

Der Teilstring ab start mit Länge len soll umgekehrt werden.
*/

void reverse_substring(char *s, int start, int len)
{
    if (len == 1)
    {
        return;
    }

    int left = start;
    int right = (start + len) - 1;

    while (left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

void test_reverse_substring(void)
{

    char s1[] = "abcdefg";
    reverse_substring(s1, 2, 3);
    test_equal_s(s1, "abedcfg");

    char s2[] = "hello";
    reverse_substring(s2, 1, 3);
    test_equal_s(s2, "hlleo");

    char s3[] = "abcdef";
    reverse_substring(s3, 0, 4);
    test_equal_s(s3, "dcbaef");

    char s4[] = "abc";
    reverse_substring(s4, 1, 1);
    test_equal_s(s4, "abc");
}

int main(void)
{

    test_reverse_substring();

    return 0;
}