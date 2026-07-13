#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"

void swapFirstTwo(char *str)
{
    char temp = str[0];
    str[0] = str[1];
    str[1] = temp;
}

// "abcd" → "aXbc"
void shiftRightAndInsertX(char *str, int length)
{
    for (int i = length - 1; i > 1; i--)
    {
        str[i] = str[i - 1];
    }

    str[1] = 'X';
}

// "abcd" → "bcda"
/**
 1. i = 0: bbcd
 2. i = 1: bccd
 3. i = 2: bcdd
 4. i = 3: Error
 */
void rotateLeftOnce(char *str, int length)
{
    char first = str[0];
    for (int i = 0; i < length - 1; i++)
    {
        str[i] = str[i + 1];
    }

    str[length - 1] = first;
}

int getTargetIndex(int current_index, int shift, int length)
{
    int newIndex = (current_index + shift) % length;
    return newIndex;
}

char *shiftCharAtIndex(char *inputString, int index, int shift)
{
    int length = s_length(inputString);

    if (length == 0)
    {
        return "";
    }

    if (length == 1)
    {
        return inputString;
    }

    char temp = inputString[index];

    int newIndex = (index + shift) % length;

    if (newIndex > index)
    {
        for (int i = index; i < newIndex; i++)
        {
            inputString[i] = inputString[i + 1];
        }
    }

    if (newIndex < index)
    {
        for (int i = index; i > newIndex; i--)
        {
            inputString[i] = inputString[i - 1];
        }
    }

    inputString[newIndex] = temp;

    return inputString;
}

int main()
{
    char test1[] = "abc";
    test_equal_s(shiftCharAtIndex(test1, 1, 1), "acb");

    char test2[] = "abc";
    test_equal_s(shiftCharAtIndex(test2, 0, 1), "bac");

    char test3[] = "abc";
    test_equal_s(shiftCharAtIndex(test3, 0, 2), "bca");

    char test4[] = "abc";
    test_equal_s(shiftCharAtIndex(test4, 0, 4), "bac");

    char test5[] = "abc";
    test_equal_s(shiftCharAtIndex(test5, 1, 0), "abc");

    char test6[] = "a";
    test_equal_s(shiftCharAtIndex(test6, 0, 5), "a");

    char test7[] = "";
    test_equal_s(shiftCharAtIndex(test7, 0, 1), "");

    return 0;

    return 0;
}