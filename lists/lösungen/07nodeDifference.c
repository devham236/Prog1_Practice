// Differenz zwischen dem minimalen und dem maximalem Element in einer Liste von INT berechnen
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct IntList
{
    int data;
    struct IntList *next;
} IntList;

IntList *newNode(int data)
{
    IntList *node = malloc(sizeof(IntList));
    node->data = data;
    node->next = NULL;
}

void push(IntList **head, int data)
{
    IntList *node = newNode(data);
    node->next = (*head);
    (*head) = node;
}

void printList(IntList *head)
{
    while (head != NULL)
    {
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\n");
}

int diffMinMax(IntList *head)
{
    int min = INT_MIN;
    int max = INT_MAX;
    while (head != NULL)
    {
        if (min < head->data)
        {
            min = head->data;
        }
        else if (max >= head->data)
        {
            max = head->data;
        }
        head = head->next;
    }
    return abs(min - max);
}

int main()
{
    IntList *testList = NULL;
    push(&testList, 2);
    push(&testList, 3);
    push(&testList, 5);
    push(&testList, 4);

    printList(testList);
    printf("%d\n", diffMinMax(testList));
}