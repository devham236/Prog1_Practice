// Verschlüsselung von Buchstaben in einem String (Caesar Alg).
// Alle Kleinbuchstaben(!) sollten um 5 chars verschoben werden
// Nur s_length/xmalloc/strlen
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

// A-Z = 65 bis 90;
// a-z = 97 bis 122;

char *encode(char *toEncode, int shift)
{
    char *result = malloc(s_length(toEncode) + 1);

    int key = shift % 26;

    if (key == 0)
    {
        return toEncode;
    }

    int j = 0;
    for (int i = 0; i < s_length(toEncode); i++)
    {
        char c = toEncode[i];

        if (!isalpha(c))
        {
            result[j] = c;
            j++;
        }

        if (c >= 97 && c <= 122)
        {
            if (c + key > 122)
            {
                int diff = (c + key) - 122;
                char newChar = (char)((97 + diff) - 1);
                result[j] = newChar;
                j++;
            }
            else
            {
                result[j] = c + key;
                j++;
            }
        }

        if (c >= 65 && c <= 90)
        {
            if (c + key > 90)
            {
                int diff = (c + key) - 90;
                char newChar = (char)((65 + diff) - 1);
                result[j] = newChar;
                j++;
            }
            else
            {
                result[j] = c + key;
                j++;
            }
        }
    }

    result[j] = '\0';

    return result;
}

int main()
{
    test_equal_s(encode("aaa", 1), "bbb");
    test_equal_s(encode("abc", 5), "fgh");
    test_equal_s(encode("xyz", 1), "yza");
    test_equal_s(encode("xyz", 5), "cde");
    test_equal_s(encode("abc", 26), "abc");
    test_equal_s(encode("abc", 27), "bcd");
    test_equal_s(encode("Hello World!", 5), "Mjqqt Btwqi!");
    test_equal_s(encode("", 5), "");
}