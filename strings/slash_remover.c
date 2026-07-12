// Für _buchstabe neuen String allokieren und "_" entfernen und den ersten Buchstaben nach "\_" groß Schreiben.
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "base.h"

char *removeSlash(char *inputString)
{
    int length = s_length(inputString);

    if(length == 0 || strcmp(inputString, "_") == 0){
        return "";
    }

    int count = 0;

    for(int i = 0; i < length; i++){
        char c = inputString[i];

        if(c != '_'){
            count++;
        }
    }


    char *result = malloc(count + 1);

    int j = 0;
    for (int i = 0; i < length; i++)
    {
        char c = inputString[i];

        if(i > 0 && isalpha(c) && inputString[i-1] == '_'){
            result[j] = toupper(c);
            j++;
        }
        else if(c != '_'){
            result[j] = c;
            j++;
        }

    }
    
    result[j] = '\0';

    return result;
}

int main()
{
    test_equal_s(removeSlash("_hello"), "Hello");
    test_equal_s(removeSlash("_welt"), "Welt");
    test_equal_s(removeSlash("_Hello"), "Hello");
    test_equal_s(removeSlash("test_wort"), "testWort");
    test_equal_s(removeSlash("_mein_test_string"), "MeinTestString");
    test_equal_s(removeSlash("fehler_1"), "fehler1");
    test_equal_s(removeSlash("test_!"), "test!");

    test_equal_s(removeSlash("keinUnterstrich"), "keinUnterstrich");
    test_equal_s(removeSlash("ende_"), "ende");
    test_equal_s(removeSlash("test__string"), "testString");
    test_equal_s(removeSlash("___a"), "A");
    test_equal_s(removeSlash("_"), "");
    test_equal_s(removeSlash(""), "");
}