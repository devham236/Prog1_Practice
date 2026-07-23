#include "base.h"

/*
Aufgabe: String in verkettete Liste umwandeln

Du bekommst einen String (z. B. "abc") und sollst eine dynamisch allokierte
verkettete Liste erstellen, die die Zeichen in derselben Reihenfolge enthält.

Beispiel: "abc" -> 'a' -> 'b' -> 'c' -> NULL
Ein leerer String "" soll NULL zurückgeben.
*/

typedef struct Node
{
    char value;
    struct Node *next;
} Node;

// Hilfsfunktion: Erstellt einen neuen Listen-Knoten auf dem Heap
Node *new_node(char val)
{
    Node *node = xmalloc(sizeof(Node));
    node->value = val;
    node->next = NULL; // Standardmäßig zeigt next auf NULL
    return node;
}

// Hilfsfunktion: Gibt die Liste auf der Konsole aus (zum Debuggen)
void print_list(Node *head)
{
    printf("[");
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        printf("'%c'", curr->value);
        if (curr->next != NULL)
            printf(", ");
    }
    printf("]\n");
}

// Hilfsfunktion: Gibt den gesamten Speicher der Liste frei
void free_list(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
}

Node *string_to_list(char *s)
{
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        Node *new = new_node(c);

        if (head == NULL)
        {
            head = new;
            tail = new;
        }
        else
        {
            tail->next = new;
            tail = new;
        }
    }

    return head;
}

void test_string_to_list(void)
{
    // Test 1: Standardfall "abc"
    Node *l1 = string_to_list("abc");
    printf("Liste 1: ");
    print_list(l1);

    // Prüfe die Werte einzeln
    test_equal_b(l1 != NULL, true);
    if (l1 != NULL)
    {
        test_equal_i(l1->value, 'a');
        test_equal_i(l1->next->value, 'b');
        test_equal_i(l1->next->next->value, 'c');
        test_equal_b(l1->next->next->next == NULL, true);
    }
    free_list(l1);

    // Test 2: Einzelnes Zeichen
    Node *l2 = string_to_list("X");
    printf("Liste 2: ");
    print_list(l2);
    if (l2 != NULL)
    {
        test_equal_i(l2->value, 'X');
        test_equal_b(l2->next == NULL, true);
    }
    free_list(l2);

    // Test 3: Leerer String
    Node *l3 = string_to_list("");
    test_equal_b(l3 == NULL, true);
    free_list(l3);
}

int main(void)
{
    test_string_to_list();
    return 0;
}