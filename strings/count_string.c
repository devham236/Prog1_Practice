// "int count_target_string(char *text, char *string)", die zählt, wie oft "string"
// in "text" vorkommt. Es darf nur gezählt werden, wenn "string" von Leerzeichen
// umschlossen wird bzw. wenn es am Ende / am Anfang steht. Gehen Sie davon aus,
// dass nur Kleinbuchstaben und Leerzeichen vorkommen. Sie dürfen nur selbst
// programmierte Hilfsfunktionen und strlen() und strncmp() verwenden.

// Beispiele (Testfälle waren in der .c-Datei bereits programmiert):

// count_target_string("abc of", "of") -> 1
// count_target_string("abcof", "of")  -> 0
// count_target_string("ofabc", "of") -> 0
// count_target_string("of abc", "of")  -> 1
// count_target_string("abc of abc of", "of") -> 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

int match_at(char* text, char* target, int index){
    if(strncmp(&text[index], target, s_length(target)) == 0){
        return 1;
    }

    return 0;
}

int is_valid_start(char *text, int index) {
    if(index == 0 || text[index - 1] == ' '){
        return 1;
    }

    return 0;
}

int is_valid_end(char *text, int index){
    if(text[index] == '\0' || text[index] == ' '){
        return 1;
    }

    return 0;
}

int countTargetString(char *text, char *string)
{
    if(s_length(text) < s_length(string)){
        return 0;
    }

    int count = 0;

    for(int i = 0; i < s_length(text); i++){
        if(match_at(text, string, i) == 1){
            if(is_valid_start(text, i) && is_valid_end(text, s_length(string) + i)){
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char *argv[])
{
    test_equal_i(countTargetString("abc of", "of"), 1);
    test_equal_i(countTargetString("abcof", "of"), 0);
    test_equal_i(countTargetString("ofabc", "of"), 0);
    test_equal_i(countTargetString("of abc", "of"), 1);
    test_equal_i(countTargetString("abc of abc of", "of"), 2);
    test_equal_i(countTargetString("of", "of"), 1);
    test_equal_i(countTargetString("of of of", "of"), 3);
    test_equal_i(countTargetString("abc  of  abc", "of"), 1);
    test_equal_i(countTargetString("", "of"), 0);
    test_equal_i(countTargetString("   of   ", "of"), 1);
    test_equal_i(countTargetString("o", "of"), 0);
    test_equal_i(countTargetString("f", "of"), 0);
    test_equal_i(countTargetString("abc ofxyz", "of"), 0);
    test_equal_i(countTargetString("xyzof abc", "of"), 0);
}