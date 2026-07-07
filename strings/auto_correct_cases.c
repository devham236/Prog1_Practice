// ersten Buchstaben eines Wortes groß den Rest klein
//     Eingabe: HELLO WORLD
//     Ausgabe: Hello World

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "base.h"

char *autocorrectCases(char inputString[])
{
    int count = 0;

    for(int i = 0; i < s_length(inputString); i++){
        count++;
    }

    char *result = malloc(count + 1);

    for(int i = 0, j = 0; i < s_length(inputString); i++){
        char c = inputString[i];

        if(i == 0 && isalpha(c)){
            result[j] = toupper(c);
            j++;
        }

        if(i > 0 && isalpha(c) && inputString[i-1] != ' '){
            result[j] = tolower(c);
            j++;
        }

        if(i > 0 && isalpha(c) && inputString[i-1] == ' '){
            result[j] = toupper(c);
            j++;
        }

        if(!isalpha(c)){
            result[j] = c;
            j++;
        }
    }

    result[s_length(result)] = '\0';

    return result;
}

int main()
{
    printf("\n");
    test_equal_s(autocorrectCases("HELLO WORLD"), "Hello World");
    test_equal_s(autocorrectCases("hello world"), "Hello World");
    test_equal_s(autocorrectCases("hElLo WoRlD"), "Hello World");
    test_equal_s(autocorrectCases("A"), "A");
    test_equal_s(autocorrectCases("a"), "A");
    test_equal_s(autocorrectCases(""), "");
    test_equal_s(autocorrectCases("   "), "   ");
    test_equal_s(autocorrectCases("  hello   world  "), "  Hello   World  ");
    test_equal_s(autocorrectCases("123 hello!"), "123 Hello!");
    test_equal_s(autocorrectCases("c-programmierung"), "C-programmierung");
}