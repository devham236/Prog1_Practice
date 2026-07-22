#include <stdio.h>

int my_strlen(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

int main(void)
{
    const char *text = "Hallo Welt";

    int length = my_strlen(text);

    printf("Die Länge von \"%s\" ist: %d\n", text, length);

    return 0;
}