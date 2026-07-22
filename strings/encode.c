#include "base.h"

/*
Encode verschlüsselt einen String. Jeder Kleinbuchstabe wird um 5 weiter im Alphabet gesetzt, alle anderen Buchstaben bleiben gleich (also a zu f, z zu e).
Ich schreib ein Beispiel in die Test-Funktion (schreib am Besten noch mehr dazu). Der zurückgegebene String von encode soll dynamisch allokiert sein.
*/

bool isCharAndLower(char c)
{
    return (c >= 'a' && c <= 'z');
}

char *encode(char *s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }

    int key = 5;

    char *result = xmalloc(count + 1);

    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];

        if (isCharAndLower(c))
        {
            char newChar = c + key;
            if (newChar > 122)
            {
                char rest = newChar - 26;
                result[j] = rest;
                j++;
            }
            else
            {
                result[j] = newChar;
                j++;
            }
        }
        else
        {
            result[j] = c;
            j++;
        }
    }

    result[j] = '\0';

    return result;
}

void test_encode(void)
{
    char *s = "abc :D xyz!!";
    char *d = encode(s);
    test_equal_s(d, "fgh :D cde!!");
}

int main(void)
{
    test_encode();
    return 0;
}
