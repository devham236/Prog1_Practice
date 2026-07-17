// make wildcard_substring && ./wildcard_substring

#include "base.h"

/*
Aufgabe:

Überprüfen, ob t Substring von s ist.

'?' in t ist ein Wildcard-Zeichen
und passt zu jedem beliebigen Zeichen.
*/

bool wildcard_substring(char* s, char* t) {

    if (s == NULL || t == NULL) {
        return false;
    }

    for (int i = 0; s[i] != '\0'; i++) {

        int j = 0;

        while (t[j] != '\0'
            && s[i + j] != '\0'
            && (t[j] == '?' || t[j] == s[i + j])) {

            j++;
        }

        if (t[j] == '\0') {
            return true;
        }
    }

    return false;
}


// ================== TESTS ==================

void test_wildcard_substring(void) {

    test_equal_b(wildcard_substring("abcdef", "cd?"), true);
    test_equal_b(wildcard_substring("abcdef", "c?e"), true);
    test_equal_b(wildcard_substring("abcdef", "c?g"), false);

    test_equal_b(wildcard_substring("hello", "he??o"), true);
    test_equal_b(wildcard_substring("hello", "h?l?o"), true);
    test_equal_b(wildcard_substring("hello", "?ell"), true);

    test_equal_b(wildcard_substring("abc", "abcd"), false);
    test_equal_b(wildcard_substring("abc", "???"), true);
    test_equal_b(wildcard_substring("abc", "????"), false);

    test_equal_b(wildcard_substring("", ""), true);
    test_equal_b(wildcard_substring("", "a"), false);
    test_equal_b(wildcard_substring("abc", ""), true);
}


// ================== MAIN ==================

int main(void) {

    test_wildcard_substring();

    return 0;
}