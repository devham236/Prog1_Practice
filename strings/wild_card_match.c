// Prüfen ob ein string t in einem string s vorkommt.
// string t kann zudem m '?' als wildchar(beliebiger character)erhalten
// Bei den Testfällen gab es zudem den Fall dass der String '' geprüft werden musste mit dem erwarteten Ergebnis true.
// "" ist die binäre Null, der String ist damit nicht leer... Dazu die Abfrage t[0] == '\0'
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "base.h"

bool wildCardMatch(char s[], char t[])
{
    return false;
}

int main()
{
    test_equal_b(wildCardMatch("Hallo Welt", ""), true);
    test_equal_b(wildCardMatch("Programmieren", "gramm"), true);
    test_equal_b(wildCardMatch("hacker", "ha?ker"), true);
    test_equal_b(wildCardMatch("Software-Katze", "?atz?"), true);
    test_equal_b(wildCardMatch("C", "C++"), false);
    test_equal_b(wildCardMatch("Hi", "???"), false);
    test_equal_b(wildCardMatch("Schraubenbaum", "raum"), false);
    return 0;
}