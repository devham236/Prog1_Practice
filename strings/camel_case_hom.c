// strings mit xmalloc kopieren über string laufen und alle lowercases in string direkt übergeben, leerzeichen auch,
// uppercases je nach position übergeben oder zu "\_x" transformieren.
// die zusätzliche größenveränderung beim allocieren natürlich vorher beachten.
// Originalstring nicht verändern.
// Rückgabestring dynmanisch allokieren.
//   - nur wenn Uppercase \_ untermische und und die innere Buchstabe zu lowercase
//   - Hilfsfunktionen
//      - is_letter()....
//      - is_upper()....
//      - is_lower()....
//      - to_upper()...
//      - to_lower()...
//   - Beispiele
//     - abcd --> abcd
//     - Abcd --> Abcd
//     - ABCD --> A_b_c_d
//     - ABCDEF --> A_b_c_d_e_f
//     - ABCD EF --> A_b_c_d E_f

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "base.h"

bool isLetter(char inputChar)
{
    bool result = false;
    if ((inputChar >= 'a' && inputChar <= 'z') || (inputChar >= 'A' && inputChar <= 'Z'))
    {
        result = true;
    }
    return result;
}

char *camelCase(char inputString[])
{
    int count = 0;

    for (int i = 0, j = 0; i < s_length(inputString); i++)
    {
        char c = inputString[i];

        if (islower(c))
        {
            count++;
        }

        if (i == 0 && isupper(c))
        {
            count++;
        }

        if (i > 0 && isupper(c))
        {
            count = count + 2;
        }

        if (!isalpha(c))
        {
            count++;
        }
    }

    printf("string length should be %d\n", count + 1);

    char *result = malloc(count + 1);

    for (int i = 0, j = 0; i < s_length(inputString); i++)
    {
        char c = inputString[i];

        if (islower(c))
        {
            result[j] = c;
            j++;
        }

        if (i == 0 && isupper(c))
        {
            result[j] = c;
            j++;
        }

        if (i > 0 && isupper(c) && inputString[i-1] != ' ')
        {
            result[j] = '_';
            j++;
            result[j] = tolower(c);
            j++;
        }

        if(i > 0 && isupper(c) && inputString[i-1] == ' '){
            result[j] = c;
            j++;
        }

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
    test_equal_s(camelCase("ABCD EF"), "A_b_c_d E_f");
    test_equal_s(camelCase("ABC 123 DE"), "A_b_c 123 D_e");
    test_equal_s(camelCase("abcd"), "abcd");
    test_equal_s(camelCase("Abcd"), "Abcd");
    test_equal_s(camelCase("ABCD"), "A_b_c_d");
    test_equal_s(camelCase("ABCDEF"), "A_b_c_d_e_f");
    
    test_equal_s(camelCase("A"), "A");
    test_equal_s(camelCase("a"), "a");
    test_equal_s(camelCase(""), "");

    return 0;
}