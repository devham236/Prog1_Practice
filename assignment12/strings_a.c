#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "base.h"

// Prototyp der Funktion
// str: Die zu prüfende Zeichenkette
// Return: true wenn alle Ziffernfolgen eine Länge aufweisen, die ein Vielfaches von 3 ist, sonst false

bool validate_digit_sequences(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];

        if (isdigit(c))
        {
            count++;
        }
        if (!isdigit(c))
        {
            if (count > 0)
            {
                if (count % 3 != 0)
                    return false;
                count = 0;
            }
        }
    }

    if (count > 0 && count % 3 != 0)
    {
        return false;
    }

    return true;
}

int main(void)
{
    // Testfälle
    const char *test1 = "123";                  // Valid (Länge 3)
    const char *test2 = "ab c de 123456";       // Valid (Länge 6)
    const char *test3 = "123 asdbderb 890";     // Valid (Längen 3 und 3)
    const char *test4 = "1234";                 // Invalid (Länge 4)
    const char *test5 = "abc 12 def 123456789"; // Invalid (Länge 2)

    printf("\"%s\" -> %s\n", test1, validate_digit_sequences(test1) ? "true" : "false");
    printf("\"%s\" -> %s\n", test2, validate_digit_sequences(test2) ? "true" : "false");
    printf("\"%s\" -> %s\n", test3, validate_digit_sequences(test3) ? "true" : "false");
    printf("\"%s\" -> %s\n", test4, validate_digit_sequences(test4) ? "true" : "false");
    printf("\"%s\" -> %s\n", test5, validate_digit_sequences(test5) ? "true" : "false");

    return 0;
}