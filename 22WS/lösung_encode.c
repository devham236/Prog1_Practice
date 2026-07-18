# include "base.h"

/*
Encode verschlüsselt einen String. Jeder Kleinbuchstabe wird um 5 weiter im Alphabet gesetzt, alle anderen Buchstaben bleiben gleich (also a zu f, z zu e).
Ich schreib ein Beispiel in die Test-Funktion (schreib am Besten noch mehr dazu). Der zurückgegebene String von encode soll dynamisch allokiert sein.
*/
char* encode(char* s) {
    char* result = xmalloc(sizeof(s)); 
    result[0] = '\0'; 

    for (int i = 0; i < s_length(s); i++){
        if(s[i] >= 97 && s[i] <= 122){

            switch(s[i]){
                case 118: 
                     result[i] = s[i] - 21;
                     break; 
                case 119: 
                     result[i] = s[i] - 21;
                     break; 
                case 120: 
                     result[i] = s[i] - 21;
                     break; 
                case 121: 
                     result[i] = s[i] - 21;
                     break; 
                case 122: 
                     result[i] = s[i] - 21;
                     break; 
                default: 
                    result[i] = s[i] +5;

                
            }
        } else{ result[i] = s[i];}
    }

    return result; 
}

void test_encode(void) {
    char* s = "abc :D xyz!!";
    char* d = encode(s);
    test_equal_s(d, "fgh :D cde!!");
    free(d); 
}

int main() {
    test_encode();
    report_memory_leaks(true); 
    return 0;
}