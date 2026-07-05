// Gibt true zurück, wenn das erste und letzte Zeichen im String gleich sind
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "base.h"

bool firstEqualsLast(char s[])
{
    int length = s_length(s);

    if(s[0] == '\0'){
        return false;
    }

    if(s_length(s) == 1){
        return true;
    }

    return s[0] == s[length - 1];
}

int main()
{
    test_equal_b(firstEqualsLast("abc"), false);
    test_equal_b(firstEqualsLast("radar"), true);
    test_equal_b(firstEqualsLast("a"), true);
    test_equal_b(firstEqualsLast(""), false);
    test_equal_b(firstEqualsLast("Anna"), false);
    test_equal_b(firstEqualsLast("!test!"), true);
}