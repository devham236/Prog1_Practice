// wie oft der gleiche Buchstabe im String vorkommt

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "base.h"

int repeatingChar(char s[], char c)
{
    if(s[0] == '\0'){
        return 0;
    }

    int count = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == c){
            count++;
        }
    }

    return count;
}

int main()
{
    test_equal_i(repeatingChar("banana", 'a'), 3);
    test_equal_i(repeatingChar("test", 't'), 2);
    test_equal_i(repeatingChar("hello", 'x'), 0);
    test_equal_i(repeatingChar("Apple", 'p'), 2);
    test_equal_i(repeatingChar("Apple", 'A'), 1);
    test_equal_i(repeatingChar("", 'a'), 0);
    test_equal_i(repeatingChar(" ", ' '), 1);
    
    return 0;
}