#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototyp der Funktion
// s1: Erste Zeichenkette
// s2: Zweite Zeichenkette (wird an s1 angehängt)
// Return: Dynamisch allokierter Zeiger auf den zusammengefügten String
char *string_concat(const char *s1, const char *s2)
{
    // TODO: Implementiere hier deine Logik
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    int j = 0;
    for(int i = 0; s1[i] != '\0'; i++){
        result[j] = s1[i];
        j++;
    }

    for(int i = 0; s2[i] != '\0'; i++){
        result[j] = s2[i];
        j++;
    }

    result[j] = '\0';

    return result;
}

int main(void)
{
    const char *text1 = "Hallo ";
    const char *text2 = "Welt!";

    char *result = string_concat(text1, text2);

    if (result != NULL)
    {
        printf("Ergebnis: \"%s\"\n", result);

        // Dynamisch allokierten Speicher wieder freigeben
        free(result);
    }
    else
    {
        printf("Fehler bei der Speicherallokierung!\n");
    }

    return 0;
}