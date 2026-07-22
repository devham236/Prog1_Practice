#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototyp der Funktion
// s1: Erste Zeichenkette
// s2: Zweite Zeichenkette
// Return: Dynamisch allokierter Zeiger auf den längsten gemeinsamen Teilstring
char *longest_common_substring(const char *s1, const char *s2) {
    // TODO: Implementiere hier deine Logik

    return NULL; // Temporärer Rückgabewert
}

int main(void) {
    const char *text1 = "Programmieren 1 macht Spass";
    const char *text2 = "Programmieren 1 macht keinen Spass";

    char *result = longest_common_substring(text1, text2);

    if (result != NULL) {
        printf("Längster gemeinsamer Teilstring: \"%s\"\n", result);
        free(result); // Speicher wieder freigeben
    }

    return 0;
}