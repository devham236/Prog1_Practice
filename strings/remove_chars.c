// Chars aus einem String entfernen
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

char *removeChar(char *inputString, char charToRemove)
{
    int count = 0;
    
    for(int i = 0; i < s_length(inputString); i++){
        char c = inputString[i];

        if(c != charToRemove){
            count++;
        }
    }

    char *result = malloc(count+1);

    for(int i = 0, j = 0; i < s_length(inputString); i++){
        char c = inputString[i];

        if(c != charToRemove){
            result[j] = c;
            j++;
        }
    }

    result[s_length(result)] = '\0';

    return result;
}

int main()
{
    test_equal_s(removeChar("abc123", 'a'), "bc123");
    test_equal_s(removeChar("abc123", '3'), "abc12");
    test_equal_s(removeChar("abc123", 'b'), "ac123");
    test_equal_s(removeChar("abc123", 'x'), "abc123");
    test_equal_s(removeChar("banana", 'a'), "bnn");
    test_equal_s(removeChar("ccccc", 'c'), "");
    test_equal_s(removeChar("", 'a'), "");
    return 0;
}