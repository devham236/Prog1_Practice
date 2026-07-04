# How To


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
```c