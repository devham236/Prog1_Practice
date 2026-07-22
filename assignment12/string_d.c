#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototyp der Funktion
// to_split: Der zu zerlegende String
// split: Das Trennzeichen
// count_out: (Hilfsparameter) speichert die Anzahl der gefundenen Teilstrings
// Return: Dynamisch allokiertes Array aus Zeigern auf die neuen Teilstrings
char **split_string(const char *to_split, char split, int *count_out)
{
    // TODO: Implementiere hier deine Logik

    int count = 1;
    for (int i = 0; i < strlen(to_split); i++)
    {
        char c = to_split[i];

        if (c == split)
        {
            count++;
        }
    }

    char **result = malloc(count * sizeof(char *));

    char temp[256];
    int temp_index = 0;
    int j = 0;
    for (int i = 0; i < strlen(to_split); i++)
    {
        char c = to_split[i];

        if (c != split)
        {
            temp[temp_index] = c;
            temp_index++;
        }
        else
        {
            temp[temp_index] = '\0';
            char *part = malloc(temp_index + 1);
            strcpy(part, temp);
            result[j] = part;
            j++;
            temp_index = 0;
        }
    }

    temp[temp_index] = '\0';
    char *part = malloc(temp_index + 1);
    strcpy(part, temp);
    result[j] = part;

    *count_out = count;

    return result;
}

int main(void)
{
    const char *text = "abc.bdfg.xyz";
    char delimiter = '.';
    int count = 0;

    char **parts = split_string(text, delimiter, &count);

    if (parts != NULL)
    {
        printf("Gefundene Teile (%d):\n", count);
        for (int i = 0; i < count; i++)
        {
            printf("Teil %d: \"%s\"\n", i + 1, parts[i]);

            // Jeden einzelnen Teilstring freigeben
            free(parts[i]);
        }
        // Das Zeiger-Array selbst freigeben
        free(parts);
    }

    return 0;
}