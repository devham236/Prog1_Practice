// Es sind 2 Strings gegeben, wenn der eine in dem anderen vorkommt, soll der String nach dem anderen String ausgegeben werden,
// sonst der ursprüngliche String.Mit allokieren
#include <stdio.h>
#include <string.h>
#include "base.h"

char *printStrings(char *string, char *searchText)
{
    char *result;

    for (int i = 0; i < s_length(string); i++)
    {
        if (strncmp(&string[i], searchText, s_length(searchText)) == 0)
        {
            result = &string[i + s_length(searchText)];
            break;
        }
        else
        {
            result = string;
        }
    }

    char *newString = malloc(s_length(result) + 1);

    strcpy(newString, result);

    return newString;
}

int main()
{
    // Test 1: Suchtext ist gar nicht enthalten -> Gibt den gesamten Ursprungsstring zurück
    test_equal_s(printStrings("Hello World", "Ghello"), "Hello World");

    // Test 2: Suchtext ist exakt am Anfang -> Gibt alles danach zurück
    test_equal_s(printStrings("Hello World", "Hello "), "World");

    // Test 3: Suchtext ist mitten drin -> Gibt den Rest danach zurück
    test_equal_s(printStrings("Ananassaft", "nana"), "ssaft");

    // Test 4: Suchtext ist am Ende -> Gibt einen leeren String "" zurück
    test_equal_s(printStrings("Programmieren", "mieren"), "");

    // Test 5: Suchtext ist identisch mit dem String -> Gibt ebenfalls "" zurück
    test_equal_s(printStrings("Test", "Test"), "");

    // Test 6: Suchtext ist leer -> JEDER String enthält theoretisch einen leeren String am Anfang
    test_equal_s(printStrings("Hello", ""), "Hello");
}