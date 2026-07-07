// nur mit hilfsfunktionen strings in exakt größen allokierten copy string übertragen, alles was letters sind ignorieren.
// Zahlen aus String rausschreiben
// Originalstring nicht verändern
// Rückgabestring dynmanisch allokieren
// nur Hilfsfunktionen verwenden und xmalloc
//     - is_letter
//     - s_length
// Beispiele
//     " " --> " "
//     "abc " --> " "
//     "1abc" --> "1"
//     "x11" --> "11"
//     "1a2b3c4d" --> "1234"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "base.h"

char *removeLetters(char inputString[])
{
    int count = 0;

    for (int i = 0; inputString[i] != '\0'; i++)
    {
        char c = inputString[i];

        if (!isalpha(c))
        {
            count++;
        }
    }

    char *result = malloc(count + 1);

    for (int i = 0, j = 0; i < s_length(inputString); i++)
    {
        char c = inputString[i];

        if (!isalpha(c))
        {
            result[j] = c;
            j++;
        }
    }

    result[s_length(result)] = '\0';

    return result;
}
int main()
{
    test_equal_s(removeLetters(" "), " ");
    test_equal_s(removeLetters("abc "), " ");
    test_equal_s(removeLetters("1abc"), "1");
    test_equal_s(removeLetters("x11"), "11");
    test_equal_s(removeLetters("1a2b3c4d"), "1234");
}