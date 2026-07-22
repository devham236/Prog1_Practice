#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototyp der Funktion
// text: Der Ursprungstext
// replace: Das zu suchende Wort / die Zeichenkette
// replacement: Der neue Text, der eingesetzt werden soll
// Return: Eine dynamisch allokierte Kopie von text mit Ersetzungen
char *find_and_replace(const char *text, const char *replace, const char *replacement)
{
}

int main(void)
{
    const char *original = "Hallo Welt, hallo C!";
    const char *search = "hallo";
    const char *rep = "Hallo";

    char *result = find_and_replace(original, search, rep);

    if (result != NULL)
    {
        printf("Original: %s\n", original);
        printf("Ergebnis: %s\n", result);

        // Dynamisch allokierten Speicher freigeben
        free(result);
    }

    return 0;
}