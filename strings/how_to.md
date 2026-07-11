# How To

### Zählen wie oft ein String in einem anderen String vorkommt

- Logik der Funktion wurde in drei separaten Funktionen gelegt (match_at, is_valid_start und is_valid_end)
- Beispieldurchlauf (test_equal_i(countTargetString("abc of", "of"), 1);):
1. Text zeigt auf "abc of", string zeigt auf "of"
2. Es wird durch text geloopt und jedesmal match_at(text, string, i) audgeführt
3. In match_at wird mit strncmp() überprüft ob der string mit der Länge i, an der Stelle i von text anfängt bzw. gleich ist. &text[index] bedeutet der Teil des String ab der Stelle index, &text[0] = 'a...' und &text[4] = 'o...'
4. strncmp(&text[4], "of", 2) vergleicht nun ab dieser Adresse genau 2 Zeichen mit dem Zielwort also "of" und gibt 1 wieder
5. Jetzt wird is_valid_start und is_valid_end überprüft
6. is_valid_start bekommt text also "abc of" und 4 übergeben
7. Es wird geschaut ob der index gleich 0 ist oder ob der char vor text[4] also text[4-1] ein Leerzeichen ist
8. is_valid_end bekommt auch text und die 6 übergeben, weil wir am index 4 einen match haben wollen wir ans Ende des strings "of" gehen, also + s_length(string), also +2 und schauen was da steht, wenn da die '\0' oder ein Leerzeichen steht ist es gültig.

```c
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
```

### Substring in einem String
- Wenn du einen bestimmten Substring in einem String suchen willst, dann musst du nested loops verwenden
- Dieses s[i+j] gibt dir immer den Teil vom String s, der bei index i startet und bei j aufhört, wenn i = 0 ist fängst du beim ersten char von s an und gehst j Schritte bzw. so viele Schritte wie die Länge von String t ist, nach rechts

```c
bool wildCardMatch(char s[], char t[])
{
    if (t[0] == '\0')
    {
        return true;
    }

    if(s_length(t) > s_length(s)){
        return false;
    }

    for (int i = 0; i < s_length(s); i++)
    {
        bool match = true;

        for (int j = 0; j < s_length(t); j++)
        {
            if (s[i + j] != t[j] && t[j] != '?')
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    test_equal_b(wildCardMatch("Hallo Welt", ""), true);
    test_equal_b(wildCardMatch("Programmieren", "gramm"), true);
    test_equal_b(wildCardMatch("hacker", "ha?ker"), true);
    test_equal_b(wildCardMatch("Software-Katze", "?atz?"), true);
    test_equal_b(wildCardMatch("C", "C++"), false);
    test_equal_b(wildCardMatch("Hi", "???"), false);
    test_equal_b(wildCardMatch("Schraubenbaum", "raum"), false);
    return 0;
}
```