// Schreiben Sie eine Funktion, die überprüft, ob in einem String 4 aufeinanderfolgende aufsteigende Zahlen auftreten.
// Beispielsweise "as53679e".

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define maxLength 4
#include "base.h"

bool isDigit(char inputChar)
{
    bool result = false;
    if (inputChar >= '0' && inputChar <= '9')
    {
        result = true;
    }
    return result;
}

bool checkString(char inputString[])
{
    int length = s_length(inputString);

    if (length < maxLength)
    {
        return false;
    }

    int count = 0;

    for (int i = 0; i < length; i++)
    {
        char c = inputString[i];

        if (i > 0 && isDigit(c) && c > inputString[i - 1])
        {
            count++;
        }

        else if (isDigit(c))
        {
            count = 1;
        }

        else if (!isDigit(c))
        {
            count = 0;
        }

        if (count >= maxLength)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // --- Block 1: Negativtests (Sollten 'false' liefern) ---

    char test01[] = "_12_34_";
    test_equal_b(checkString(test01), false); // Unterbrochen durch Unterstrich

    char test02[] = "abc123xyz";
    test_equal_b(checkString(test02), false); // Nur 3 aufeinanderfolgende Zahlen (zu kurz)

    char test03[] = "4321";
    test_equal_b(checkString(test03), false); // Absteigend, nicht aufsteigend

    char test04[] = "2222";
    test_equal_b(checkString(test04), false); // Gleichbleibend, nicht aufsteigend

    char test05[] = "1317";
    test_equal_b(checkString(test05), false); // Aufsteigend, aber nicht direkt aufeinanderfolgend (+2er Schritte)

    // --- Block 2: Positivtests (Sollten 'true' liefern) ---

    char test06[] = "abc1234xyz";
    test_equal_b(checkString(test06), true); // Standardfall mitten im String

    char test07[] = "3456";
    test_equal_b(checkString(test07), true); // Exakt 4 Zeichen lang und gültig

    char test08[] = "7890abc";
    test_equal_b(checkString(test08), false); // Direkt am Start des Strings

    char test09[] = "xyz6789";
    test_equal_b(checkString(test09), true); // Direkt am Ende des Strings

    char test10[] = "012345";
    test_equal_b(checkString(test10), true); // Längere Kette als 4 (enthält "0123")

    // --- Block 3: Grenzfälle / Edge Cases (Sollten 'false' liefern) ---

    char test11[] = "";
    test_equal_b(checkString(test11), false); // Komplett leerer String

    char test12[] = "123";
    test_equal_b(checkString(test12), false); // String ist kürzer als die geforderten 4 Zeichen

    return 0;
}