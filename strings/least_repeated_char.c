// make least_repeated_char && ./least_repeated_char

#include "base.h"

/*
Aufgabe:

Zähle wie oft jedes Zeichen in einem String vorkommt.

Gib das Zeichen zurück, das am seltensten vorkommt.
Die Anzahl soll in den Pointer count geschrieben werden.

Ein einzelnes Zeichen zählt auch als Wiederholung.
Bei Gleichstand wird das erste Zeichen im String genommen.
*/

void set_to_ten(int *ptr)
{
    *ptr = 10;
}

int count_char(char *s, char target)
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];

        if (c == target)
        {
            count++;
        }
    }

    return count;
}

int find_min(int nums[], int len)
{

    int min = nums[0];

    for (int i = 1; i < len; i++)
    {
        int curr = nums[i];

        if (curr < min)
        {
            printf("current %d is lesser than min %d\n", curr, min);
            min = curr;
        }
        else if (curr == min)
        {
            printf("current %d is equal to min %d\n", curr, min);
        }
        else
        {
            printf("current %d is greater than min %d\n", curr, min);
        }

        printf("min is currently: %d\n", min);
    }

    printf("final min is: %d\n", min);
    return min;
}

char least_repeated_char(char *s, int *count)
{
    if (s[0] == '\0')
    {
        *count = 0;
        return '\0';
    }

    int ascii_arr[256] = {0};

    for (int i = 0; s[i] != '\0'; i++)
    {
        ascii_arr[(unsigned char)s[i]]++;
    }

    char least_c = s[0];
    int min = ascii_arr[(unsigned char)s[0]];

    for (int i = 0; s[i] != '\0'; i++)
    {
        char curr = s[i];

        if (ascii_arr[(unsigned char)curr] < min)
        {
            min = ascii_arr[(unsigned char)curr];
            least_c = curr;
        }
    }

    *count = min;
    return least_c;
}

// ================== TESTS ==================

void test_least_repeated_char(void)
{

    int c;

    test_equal_c(least_repeated_char("aabbc", &c), 'c');
    test_equal_i(c, 1);

    test_equal_c(least_repeated_char("abacbbd", &c), 'c');
    test_equal_i(c, 1);

    test_equal_c(least_repeated_char("aaaa", &c), 'a');
    test_equal_i(c, 4);

    test_equal_c(least_repeated_char("abc", &c), 'a');
    test_equal_i(c, 1);

    test_equal_c(least_repeated_char("", &c), '\0');
    test_equal_i(c, 0);
}

// ================== MAIN ==================

int main(void)
{

    test_least_repeated_char();

    return 0;
}