// 2 Strings gegeben.
// Alle chars die in String 1 vorkommen, aber nicht in String 2 in einen neuen allokierten String übergeben
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

bool contains(char *str, char c)
{

    for (int i = 0; i < s_length(str); i++)
    {
        char curr = str[i];

        if (curr == c)
        {
            return true;
        }
    }

    return false;
}

int countDiffChars(char *str1, char *str2)
{
    int count = 0;

    for (int i = 0; i < s_length(str1); i++)
    {
        char c = str1[i];

        if (!contains(str2, c))
        {
            count++;
        }
    }

    return count;
}

char *duplicateString(char *str)
{
    char *result = malloc(s_length(str) + 1);

    int j = 0;
    for (int i = 0; i < s_length(str); i++)
    {
        result[j] = str[i];
        j++;
    }

    result[j] = '\0';

    return result;
}

char *stringDiff(char *string1, char *string2)
{
    int length = countDiffChars(string1, string2);

    char *result = malloc(length + 1);

    int j = 0;
    for(int i = 0; i < s_length(string1); i++){
        char c = string1[i];

        if(!contains(string2, c)){
            result[j] = c;
            j++;
        }
    }

    return result;
}

int main()
{
    test_equal_s(stringDiff("HeTestllo", "Test"), "Hello");
    test_equal_s(stringDiff("abcdef", "xyz"), "abcdef");
    test_equal_s(stringDiff("abc", "abc"), "");
    test_equal_s(stringDiff("", "abc"), "");
    test_equal_s(stringDiff("abc", ""), "abc");
    test_equal_s(stringDiff("", ""), "");
    test_equal_s(stringDiff("AaaaaB", "a"), "AB");
    test_equal_s(stringDiff("Hallo Welt", " "), "HalloWelt");

    return 0;
}