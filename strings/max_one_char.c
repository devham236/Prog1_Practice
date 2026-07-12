// Prüfen ob String mit
// - : anfängt oder aufhört,
// - maximal 1x : hat,
// - nur aus kleinen Buchstaben besteht
// - und mindestens einen kleinen Buchstaben hat

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "base.h"

bool stringChecker(char currentString[])
{
    bool startsOrEndsWith = false;
    int maxOneCount = 0;
    bool onlyLowerCase = true;
    int minOneLowerCaseCount = 0;

    int length = s_length(currentString);

    if (currentString[0] == ':')
    {
        startsOrEndsWith = true;
    }

    if (!startsOrEndsWith && currentString[length - 1] == ':')
    {
        startsOrEndsWith = true;
    }

    for (int i = 0; i < length; i++)
    {
        char c = currentString[i];

        if ((isupper(c) || !isalpha(c)) && i > 0 && i != length - 1)
        {
            onlyLowerCase = false;
        }

        if (islower(c))
        {
            minOneLowerCaseCount++;
        }

        if (c == ':')
        {
            maxOneCount++;
        }
    }

    return startsOrEndsWith && maxOneCount <= 1 && onlyLowerCase && minOneLowerCaseCount >= 1;
}

int main()
{

    test_equal_b(stringChecker(":a"), true);
    test_equal_b(stringChecker(":asbdas"), true);
    test_equal_b(stringChecker("a:"), true);
    test_equal_b(stringChecker("asbdas:"), true);
    test_equal_b(stringChecker("asbdas"), false);
    test_equal_b(stringChecker("as:bdas"), false);
    test_equal_b(stringChecker(":asbdas:"), false);
    test_equal_b(stringChecker("::asbdas"), false);
    test_equal_b(stringChecker(":asbDas"), false);
    test_equal_b(stringChecker("aSbdas:"), false);
    test_equal_b(stringChecker(":asb1as"), false);
    test_equal_b(stringChecker("asb!as:"), false);
    test_equal_b(stringChecker(":"), false);
    test_equal_b(stringChecker(""), false);

    return 0;
}