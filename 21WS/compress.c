#include "base.h"

String compress(String s){
   
    int count = 1; 
    //man sollte zwingend den index für final extern festlegen, sonst rennt man in einen seg fault, keine Ahnung warum tbh
    int final_index = 0; 
    int len = s_length(s); 
    String final = xmalloc(len*2 * sizeof(char)); 
    
    


    for(int i = 0; i < len; i++){
        if(s[i] == s[i+1]){
            
            count++; 
            
        }else{
             if(count == 1){
                //wir wollen keine 1 vor einem Buchstaben haben, wenn er nur einmal vorkommt
                final[final_index++] = s[i]; 

             }else{
                //wenn der count >1 ist wollen wir ihn stehen haben und das machen wir über die ASCII-Tabelle 48 entspricht dabei 0 
                final[final_index++] = 48 + count; 
                final[final_index++] = s[i]; 
                //wir müssen count logischerweise reseten 
                count = 1; 
             }
            
            
        }
    }
    

    final[final_index] = '\0'; 
    return final; 
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