// Aus einem String die Länge der kürzesten Folge des Char c finden.
// Dazu noch Funktion schreiben die herausfindet ob der String mit einer Ziffer beginnt.

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "base.h"

bool startWithNumber(char *currentString)
{
    return isdigit(currentString[0]);
}

int shortestOrder(char *currentString)
{
    int count = 0;
    int result = s_length(currentString);
    bool found_any = false;

    for (int i = 0; i <= s_length(currentString); i++)
    {
        char c = currentString[i];

        if (c == 'a')
        {
            count++;
        }
        else
        {
            if (count > 0)
            {
                result = count < result ? count : result;
                found_any = true;
                count = 0;
            }
        }
    }

    if (!found_any)
    {
        return 0;
    }

    return result;
}

int main()
{
    // Tests für startWithNumber
    // test_equal_b(startWithNumber("1asbdas"), true);
    // test_equal_b(startWithNumber("9abc"), true);
    // test_equal_b(startWithNumber("abc1"), false);
    // test_equal_b(startWithNumber(""), false);
    // test_equal_b(startWithNumber("-5abc"), false);

    // Tests für shortestOrder (Beispielhaft für das Zeichen 'a')
    test_equal_i(shortestOrder("bbaaabbbaaaab"), 3);
    test_equal_i(shortestOrder("ababaa"), 1);
    test_equal_i(shortestOrder("aaaaa"), 5);
    test_equal_i(shortestOrder("xyz"), 0);
    test_equal_i(shortestOrder(""), 0);
}