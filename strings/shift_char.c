#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"

char *shiftCharAtIndex(char *inputString, int index, int shift)
{
    return NULL;
}

int main()
{
    // ---- STANDARD-TESTS ----

    // 'b' (Index 1) um 1 Stelle nach rechts verschieben
    // "abc" -> 'b' wandert nach rechts, 'c' rutscht vor
    test_equal_s(shiftCharAtIndex("abc", 1, 1), "acb");

    // 'a' (Index 0) um 1 Stelle nach rechts verschieben
    // "abc" -> 'a' wandert auf Index 1, 'b' rutscht vor
    test_equal_s(shiftCharAtIndex("abc", 0, 1), "bac");

    // Zyklische Rotation: 'a' (Index 0) um 2 Stellen nach rechts verschieben
    // "abc" -> 'a' landet ganz hinten, 'b' und 'c' rutschen nach vorne
    test_equal_s(shiftCharAtIndex("abc", 0, 2), "bca");


    // ---- ERWEITERTE TESTS & RANDFÄLLE ----

    // Großer Shift-Wert: Wenn shift größer als die Stringlänge ist (z.B. shift = 4 bei Länge 3)
    // Das sollte sich dank Rotation genauso verhalten wie shift = 1
    test_equal_s(shiftCharAtIndex("abc", 0, 4), "bac");

    // Keine Verschiebung (shift = 0) -> String bleibt gleich
    test_equal_s(shiftCharAtIndex("abc", 1, 0), "abc");

    // Einzelliger String -> Kann nicht verschoben werden
    test_equal_s(shiftCharAtIndex("a", 0, 5), "a");

    // Leerer String -> Bleibt leer
    test_equal_s(shiftCharAtIndex("", 0, 1), "");

    return 0;
}