#include "base.h"

/*
Aufgabe: Atbash-Verschlüsselung
Bekommst einen String und sollst ihn verschlüsseln, indem jeder Buchstabe im Alphabet gespiegelt wird:
- Kleinbuchstaben: 'a' -> 'z', 'b' -> 'y', ..., 'z' -> 'a'
- Großbuchstaben: 'A' -> 'Z', 'B' -> 'Y', ..., 'Z' -> 'A'
- Alle anderen Zeichen (Zahlen, Satzzeichen, Leerzeichen) bleiben unverändert.

Der zurückgegebene String von encode muss dynamisch allokiert sein!
*/

bool is_lower(char c)
{
    return (c >= 'a' && c <= 'z');
}

bool is_upper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

char *encode(char *s)
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }

    char *result = malloc(count + 1);

    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];

        if (is_lower(c) || is_upper(c))
        {
            if (is_lower(c))
            {
                char newChar = 122 - (c - 97);
                result[j] = newChar;
                j++;
            }
            if (is_upper(c))
            {
                char newChar = 65 - (c - 90);
                result[j] = newChar;
                j++;
            }
        }
        else
        {
            result[j] = c;
            j++;
        }
    }

    result[j] = '\0';

    return result;
}

void test_encode(void)
{
    // Test 1: Standardfall mit Kleinbuchstaben & Satzzeichen
    char *d1 = encode("abc :D xyz!!");
    test_equal_s(d1, "zyx :W cba!!");

    // Test 2: Gemischte Groß- und Kleinschreibung
    char *d2 = encode("Hello World");
    test_equal_s(d2, "Svool Dliow");

    // Test 3: Nur Großbuchstaben
    char *d3 = encode("ABCXYZ");
    test_equal_s(d3, "ZYXCBA");

    // Test 4: Zahlen und Sonderzeichen bleiben unberührt
    char *d4 = encode("12345!@#$?");
    test_equal_s(d4, "12345!@#$?");

    // Test 5: Leerer String
    char *d5 = encode("");
    test_equal_s(d5, "");

    // Test 6: Symmetrie-Test (Doppeltes Verschlüsseln ergibt wieder das Original)
    char *original = "Geheimnis 123";
    char *enc = encode(original);
    char *dec = encode(enc);
    test_equal_s(dec, original);
}

int main(void)
{
    test_encode();
    return 0;
}