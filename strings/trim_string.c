// Leerzeichen am Anfang/Ende eines Strings entfernen. Es darf nur s_length/xmalloc/strlen verwendet

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

char *trimString(char *inputString)
{
    int count = 0;

    for (int i = 0; i < s_length(inputString); i++)
    {
        char c = inputString[i];
        if (c != ' ')
        {
            count++;
        }
        if (i > 0 && c == ' ' && inputString[i - 1] != ' ' && inputString[i + 1] != ' ')
        {
            count++;
        }
    }

    char *result = malloc(count + 1);

    int j = 0;
    for (int i = 0; i < s_length(inputString); i++)
    {
        char c = inputString[i];
        if (c != ' ')
        {
            result[j] = c;
            j++;
        }
        if (i > 0 && c == ' ' && inputString[i - 1] != ' ' && inputString[i + 1] != ' ' && i != s_length(inputString) - 1)
        {
            result[j] = c;
            j++;
        }
    }

    result[j] = '\0';
    return result;
}

int main()
{
    test_equal_s(trimString(" Hello "), "Hello");
    test_equal_s(trimString("Hello"), "Hello");
    test_equal_s(trimString("   Hello"), "Hello");
    test_equal_s(trimString("Hello   "), "Hello");
    test_equal_s(trimString("Hello World"), "Hello World");
    test_equal_s(trimString("  Hello World  "), "Hello World");
    test_equal_s(trimString("   "), "");
    test_equal_s(trimString(""), "");
}