// Implementieren Sie die Funktion in sequencePosition(String s, String t).
// Diese soll die Indexposition des ersten Auftretens von t in s zurückgeben(-1 falls t nicht in s vorkommt).
// Dabei sind '?' Jokerzeichen(wildcards).
// Ein ? in t bedeutet, dass das zugehörige Zeichen in s ein beliebiges(einzelnes) Zeichen sein darf.
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "base.h"

int sequencePosition(char s[], char t[])
{
    int sl = s_length(s);
    int tl = s_length(t);

    for (int i = 0; i < sl; i++)
    {
        bool match = true;
        for (int j = 0; j < tl; j++)
        {
            if (s[i + j] != t[j] && t[j] != '?')
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    test_equal_i(sequencePosition("abcdef", "abc"), 0);
    test_equal_i(sequencePosition("abcdef", "cde"), 2);
    test_equal_i(sequencePosition("abcdef", "def"), 3);
    test_equal_i(sequencePosition("abcdef", "xyz"), -1);

    test_equal_i(sequencePosition("abcdef", "a?c"), 0);
    test_equal_i(sequencePosition("abcdef", "cd?"), 2);
    test_equal_i(sequencePosition("abcdef", "???"), 0);
    test_equal_i(sequencePosition("abcdef", "a?x"), -1);

    test_equal_i(sequencePosition("ab", "abcdef"), -1);
    test_equal_i(sequencePosition("ababab", "ba"), 1);
    test_equal_i(sequencePosition("abcabcefg", "abce"), 3);
    test_equal_i(sequencePosition("abcdef", ""), 0);

    return 0;
}