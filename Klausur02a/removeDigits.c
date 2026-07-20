// run make removeDigits && ./removeDigits
/*
	Methode soll Zahlen aus dem String entfernen.
	Es dürfen nur xmalloc und isDigit benutzt werden.
*/
#include "base.h"

bool isDigit(char c){
	return c <= '9' && c >= '0';
}

char* removeDigits(char* s){
	return "Error";
}

void test_removeDigits(void) {
    test_equal_s(removeDigits(""), "");
	test_equal_s(removeDigits("x"), "x");
	test_equal_s(removeDigits("11"), "");
	test_equal_s(removeDigits("1x1x"), "xx");
	test_equal_s(removeDigits("111x111"), "x");
	test_equal_s(removeDigits("1a2b3c4"), "abc");
	test_equal_s(removeDigits("101191xk"), "xk");
 }
 
int main(void) {
    test_removeDigits();
	report_memory_leaks(true);
    return 0;
}