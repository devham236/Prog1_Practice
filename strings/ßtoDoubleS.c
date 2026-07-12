// ss in einem String mit ß ersetzen.
// const String ss = „ß“ war gegeben.
// Anmerkung in der Aufgabe: strlen(ß) = 2.

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

char *sharpStoDoubleS(char *inputString)
{
    int length = strlen(inputString);

    if (length < 1) {

        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char *result = malloc(length + 1);

    int j = 0;
    
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1 && inputString[i] == 's' && inputString[i+1] == 's') {
            
            memcpy(&result[j], "ß", 2);
            
            j += 2;
            i++;
        }
        else {
            result[j] = inputString[i];
            j++;
        }
    }
    
    result[j] = '\0';

    return result;
    
}

int main()
{
    test_equal_s(sharpStoDoubleS("Strasse"), "Straße");
    test_equal_s(sharpStoDoubleS("Fluss"), "Fluß");
    test_equal_s(sharpStoDoubleS("ss"), "ß");
    // test_equal_s(sharpStoDoubleS("wassser"), "waßer");
    // test_equal_s(sharpStoDoubleS("Schlossstrasse"), "Schloßstraße");
    test_equal_s(sharpStoDoubleS("s"), "s");
    test_equal_s(sharpStoDoubleS("Haus"), "Haus");
    test_equal_s(sharpStoDoubleS(""), "");

    return 0;
}