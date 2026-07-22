#include "base.h"

String compress(String s){
   
}

void test(){
    String test = "BBAAAABCC"; 
    String test1 = "BBCAAABCC"; 
    String test2 = "CCAABCC"; 

    String test_lö = "2B4AB2C"; 
    String test_lö1 = "2BC3AB2C"; 
    String test_lö2 = "2C2AB2C"; 

    String check = compress(test); 
    String check1 = compress(test1); 
    String check2 = compress(test2); 

    // printf("%s \n", check); 
    // printf("%s \n", check1); 
    // printf("%s \n", check2); 

    test_equal_s(check, test_lö); 
    test_equal_s(check1, test_lö1); 
    test_equal_s(check2, test_lö2); 
    
    free(check); 
    free(check1); 
    free(check2); 
    
}

int main(){

    test(); 
    //immer die memory leaks checken, auch wenn es hier nicht übertrieben wichtig wäre, in der Klausur verzeiht dir das keiner 
    report_memory_leaks(true); 
    return 0; 
}