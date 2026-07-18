#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <base.h>

/*
Encode verschlüsselt einen String. Jeder Kleinbuchstabe wird um 5 weiter im Alphabet gesetzt, alle anderen Buchstaben bleiben gleich (also a zu f, z zu e).
Der zurückgegebene String von encode soll dynamisch allokiert sein.
*/
char* encode(char* s) {
    int len = strlen(s);
    char* result = xmalloc(len * sizeof(s)); 
    result[0] = '\0'; 
    for (int i = 0; i < len; i++) {
        char c = s[i];

        if ('a' <= c && 'z' >= c) {
            switch (c) {
                case (0 + 'a'):
                result[i] = 5 + 'a';
                break;
                case (1 + 'a'):
                result[i] = 6 + 'a';
                break;
                case (2 + 'a'):
                result[i] = 7 + 'a';
                break;
                case (3 + 'a'):
                result[i] = 8 + 'a';
                break;
                case (4 + 'a'):
                result[i] = 9 + 'a';
                break;
                case (5 + 'a'):
                result[i] = 10 + 'a';
                break;
                case (6 + 'a'):
                result[i] = 11 + 'a';
                break;
                case (7 + 'a'):
                result[i] = 12 + 'a';
                break;
                case (8 + 'a'):
                result[i] = 13 + 'a';
                break;
                case (9 + 'a'):
                result[i] = 14 + 'a';
                break;
                case (10 + 'a'):
                result[i] = 15 + 'a';
                break;
                case (11 + 'a'):
                result[i] = 16 + 'a';
                break;
                case (12 + 'a'):
                result[i] = 17 + 'a';
                break;
                case (13 + 'a'):
                result[i] = 18 + 'a';
                break;
                case (14 + 'a'):
                result[i] = 19 + 'a';
                break;
                case (15 + 'a'):
                result[i] = 20 + 'a';
                break;
                case (16 + 'a'):
                result[i] = 21 + 'a';
                break;
                case (17 + 'a'):
                result[i] = 22 + 'a';
                break;
                case (18 + 'a'):
                result[i] = 23 + 'a';
                break;
                case (19 + 'a'):
                result[i] = 24 + 'a';
                break;
                case (20 + 'a'):
                result[i] = 25 + 'a';
                break;
                case (21 + 'a'):
                result[i] = 0 + 'a';
                break;
                case (22 + 'a'):
                result[i] = 1 + 'a';
                break;
                case (23 + 'a'):
                result[i] = 2 + 'a';
                break;
                case (24 + 'a'):
                result[i] = 3 + 'a';
                break;
                case (25 + 'a'):
                result[i] = 4 + 'a';
                break;
            }
            // Bad practice code: Verry unoptimized! Not cache local!
            //int alpha_num = c - 'a';
            //int new_alpha_num = (alpha_num + 5) % 26;
            //result[i] = new_alpha_num + 'a';
        } else {
            result[i] = c;
        }
    }
    return result;
}

void test_encode(void) {
    char* s = "abc :D xyz!!\n";
    char* d = encode(s);
    test_equal_s(d, "fgh :D cde!!");
}

int main(void) {
    test_encode();
    return 0;
}