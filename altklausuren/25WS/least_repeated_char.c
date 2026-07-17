// make least_repeated_char && ./least_repeated_char

#include "base.h"

/*
Aufgabe:

Zähle wie oft jedes Zeichen in einem String vorkommt.

Gib das Zeichen zurück, das am seltensten vorkommt.
Die Anzahl soll in den Pointer count geschrieben werden.

Ein einzelnes Zeichen zählt auch als Wiederholung.
Bei Gleichstand wird das erste Zeichen im String genommen.
*/

char least_repeated_char(char* s, int* count) {

    if (s == NULL || s[0] == '\0') {
        *count = 0;
        return '\0';
    }

    int freq[256] = {0};

    // Häufigkeiten zählen
    for (int i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
    }

    char result = s[0];
    int min = freq[(unsigned char)s[0]];

    // kleinstes Vorkommen suchen
    for (int i = 0; s[i] != '\0'; i++) {

        int f = freq[(unsigned char)s[i]];

        if (f < min) {
            min = f;
            result = s[i];
        }
    }

    *count = min;
    return result;
}


// ================== TESTS ==================

void test_least_repeated_char(void) {

    int c;

    test_equal_c(least_repeated_char("aabbc", &c), 'c');
    test_equal_i(c, 1);

    test_equal_c(least_repeated_char("abacbbd", &c), 'c');
    test_equal_i(c, 1);

    test_equal_c(least_repeated_char("aaaa", &c), 'a');
    test_equal_i(c, 4);

    test_equal_c(least_repeated_char("abc", &c), 'a');
    test_equal_i(c, 1);

    test_equal_c(least_repeated_char("", &c), '\0');
    test_equal_i(c, 0);
}


// ================== MAIN ==================

int main(void) {

    test_least_repeated_char();

    return 0;
}