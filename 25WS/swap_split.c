// make swap_split && ./swap_split

#include "base.h"
#include <string.h>

/*
Aufgabe:

Ein String s und ein Index i werden gegeben.

Der String soll an der Stelle i geteilt werden.
Die beiden Teile sollen vertauscht werden.

Beispiel:
"abc12", i=3 -> "12abc"
*/

char* swap_split(char* s, int i) {

    int len = strlen(s);

    char* result = xmalloc(len + 1);

    int k = 0;

    // zweiter Teil zuerst
    for (int j = i; j < len; j++) {
        result[k++] = s[j];
    }

    // erster Teil danach
    for (int j = 0; j < i; j++) {
        result[k++] = s[j];
    }

    result[k] = '\0';

    return result;
}


// ================== TESTS ==================

void test_swap_split(void) {

    char* r;

    r = swap_split("abc12", 3);
    test_equal_s(r, "12abc");

    r = swap_split("hello", 2);
    test_equal_s(r, "llohe");

    r = swap_split("abcdef", 0);
    test_equal_s(r, "abcdef");

    r = swap_split("abcdef", 6);
    test_equal_s(r, "abcdef");
}


// ================== MAIN ==================

int main(void) {

    test_swap_split();

    return 0;
}