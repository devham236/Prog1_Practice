/*
make decompress && ./decompress
*/
#include "base.h"

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int decompressed_length(String s) {
    require_not_null(s);
    int d = 0;
    char c;
    while ((c = *s) != 0) {
        if (is_digit(c)) {
            d += (c - '0');
            s += 2;
        } else {
            d++;
            s++;
        }
    }
    return d;
}

// <purpose statement>
/*
Funktion welche einen komprimierten String decomprimiert
@param String s, komprimierter input String welcher dekomprimiert werden soll.
@return String s, wenn keine Zahlen gefunden wurden oder größe 0 ist
@return String new_text, dekomprimierter Text
*/
String decompress(String s) {
    require_not_null(s);
	if(strlen(s) == 0) return s; //länge 0 keine dekomprimierung möglich
	int index = 0;
	int index2 = 0;
	int amount = 0;
	int size = 0;
	bool toggle = false;
	char current_char;
	while(index < strlen(s)){ //bestimmen der Größe des neuen Strings nach dekomprimierung
		if(is_digit(s[index]) == true){
			size = size + s[index] - 48;
			toggle = true;
		}else{
			size++;
		}
		index++;
	}
	if(toggle == false) return s; //keine Zahl gefunden, wäre ein schon dekomprimierter String
	index = 0;
	char* new_text = xmalloc((size + 1) * sizeof(char));
	while(index2 < strlen(new_text)){ //Einfügen der Charakter nach Index
		if(is_digit(s[index]) == false){ //wenn keine Zahl vorliegt, char normal einspeichern in neuen String
			new_text[index2] = s[index];
		}
		if(is_digit(s[index]) == true){ //wenn eine Zahl vorliegt -> Anzahl an gleichen Charakteren je nach Zahl einfügen
			current_char = s[index+1];
			amount = s[index] - 48; //umformung eines char repräsentativ für eine Zahl zu einem int '0' -> 0 bspw.
			while(amount != 0){ //Einfügen der gleichen Chars
				new_text[index2] = current_char;
				amount--;
				index2++;
			}
			index++;
			index2--;
			amount = 0;
		}
		index++;
		index2++;
	}
	new_text[index2] = '\0';
    return new_text;
}

void test(void) {
    test_equal_i(decompressed_length(""), 0);
    test_equal_i(decompressed_length("Sample String"), strlen("Sample String"));
    test_equal_i(decompressed_length("He2lo World"), strlen("Hello World"));
    test_equal_i(decompressed_length("4A4B4C"), strlen("AAAABBBBCCCC"));
    test_equal_i(decompressed_length("3F3d6B3eE2e"), strlen("FFFdddBBBBBBeeeEee"));

    test_equal_s(decompress(""), "");
    test_equal_s(decompress("Sample String"), "Sample String");
    test_equal_s(decompress("He2lo World"), "Hello World");
    test_equal_s(decompress("4A4B4C"), "AAAABBBBCCCC");
    test_equal_s(decompress("9A3A"), "AAAAAAAAAAAA");
    test_equal_s(decompress("B9A3AB"), "BAAAAAAAAAAAAB");
    test_equal_s(decompress("B9A3A9BB"), "BAAAAAAAAAAAABBBBBBBBBB");
    test_equal_s(decompress("9AA"), "AAAAAAAAAA");
    test_equal_s(decompress("3F3d6B3eE2e"), "FFFdddBBBBBBeeeEee");
}

int main(void) {
    test();
    return 0;
}