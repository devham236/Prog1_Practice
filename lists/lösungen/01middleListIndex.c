//  Schreiben Sie eine Funktion, die das mittlere Element einer
//  verketteten Listen zurückgibt. Wenn die Liste eine gerade Anzahl an Elementen hat
//  soll eine Null zurückgegeben werden.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

typedef struct IntList
{
    int data;
    struct IntList *next;
} IntList;

IntList *newNode(int data)
{
    IntList *node = malloc(sizeof(IntList));
    node->data = data;
    node->next = malloc(sizeof(IntList));
    return node;
}

void push(IntList **head, int data)
{
    IntList *temp = newNode(data);
    temp->next = (*head);
    (*head) = temp;
}

void printList(IntList *head)
{
    IntList *temp = head;
    while (temp != NULL)
    {
        printf("%d,", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int getListSize(IntList *head)
{
    IntList *temp = head;
    int result = 0;
    while (temp != NULL)
    {
        result++;
        temp = temp->next;
    }
    return result;
}

int getMidIndexData(IntList *head)
{
    int result = 0;
    IntList *temp = head;
    int listSize = getListSize(head);
    if (listSize % 2 == 0)
    {
        return result;
    }
    else
    {
        int i = 0;
        while (i != ceil(listSize / 2 + 1))
        {
            result = temp->data;
            temp = temp->next;
            i++;
        }
    }
    return result;
}

int main()
{
    IntList *head = NULL;
    int maxAmount = 11;
    int upperLimit = 20;
    srand(time(NULL));
    for (int i = 0; i < maxAmount; i++)
    {
        push(&head, rand() % upperLimit);
    }
    printList(head);
    printf("%d\n", getMidIndexData(head));
}