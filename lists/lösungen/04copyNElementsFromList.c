// Liste mit Zahlen gegeben, die ersten n Elemente in neuer Liste speichern und zurückgeben,
// falls n > Listengröße komplette Liste zurückgeben, falls n = 0 nichts zurückgeben
// Eingabe: Liste(1, 2, 3), n = 2
// Rückgabe(1, 2)
#include <stdlib.h>
#include <stdio.h>

typedef struct IntList
{
    int data;
    struct IntList *next;
} IntList;

IntList *newNode(int data)
{
    IntList *temp = malloc(sizeof(IntList));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(IntList **head, int data)
{
    IntList *temp = newNode(data);
    temp->next = (*head);
    (*head) = temp;
}

IntList *append(IntList *head, int data)
{
    IntList *copy = head;
    IntList *temp = copy;
    IntList *new = newNode(data);
    while (copy->next != NULL)
    {
        copy = copy->next;
    }
    copy->next = new;
    return temp;
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

int getListSize(IntList *head)
{
    int result = 0;
    while (head != NULL)
    {
        result++;
        head = head->next;
    }
    return result;
}

IntList *getNElements(IntList *head, int n)
{
    IntList *result = NULL;
    int listSize = getListSize(head);
    if (n >= listSize)
    {
        return head;
    }
    else if (n == 0)
    {
        return NULL;
    }
    else
    {
        int i = 1;
        while (i != n)
        {
            push(&result, head->data);
            head = head->next;
            i++;
        }
        return result;
    }
}

int main()
{
    IntList *head = NULL;
    push(&head, 2);
    push(&head, 3);
    append(head, 4);
    printList(getNElements(head, 2));
}