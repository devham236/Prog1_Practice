# include "base.h"

/*
Encode verschlüsselt einen String. Jeder Kleinbuchstabe wird um 5 weiter im Alphabet gesetzt, alle anderen Buchstaben bleiben gleich (also a zu f, z zu e).
Ich schreib ein Beispiel in die Test-Funktion (schreib am Besten noch mehr dazu). Der zurückgegebene String von encode soll dynamisch allokiert sein.
*/
char* encode(char* s) {
    int n = strlen(s);
    char *result = malloc(sizeof(n));

    for(int i=0; s[i] !='\0'; i++){
         if(s[i]>='a' && s[i]<='z' ){
            result[i]= 'a' + (s[i]-'a' +5)%26;
         }
         else{
            result[i]= s[i];
         }
    }
    return result; //todo: implement

}

void test_encode(void) {
    char* s = "abc :D xyz!!";
    char* d = encode(s);
    test_equal_s(d, "fgh :D cde!!");
}

int main(void) {
    test_encode();
    return 0;
}
