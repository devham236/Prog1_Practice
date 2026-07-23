#include "base.h"

/*
Aufgabe: Liste aus Anweisungs-Array aufbauen

Du bekommst ein Array von Anweisungen (Instruction) und dessen Länge.
Jede Anweisung enthält:
- einen Integer-Wert (value)
- eine Position (pos): FRONT oder BACK

Je nach Anweisung soll der Wert entweder am Anfang (FRONT)
oder am Ende (BACK) der Liste angefügt werden.

Beispiel:
Anweisungen: {BACK, 5}, {FRONT, 1}, {FRONT, 3}
Ergebnis: [3, 1, 5]
*/

typedef enum Pos
{
    FRONT,
    BACK
} Pos;

typedef struct Instruction
{
    Pos pos;
    int value;
} Instruction;

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

// Hilfsfunktion: Erstellt einen neuen Listen-Knoten für int-Werte
Node *new_node(int val)
{
    Node *node = xmalloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    return node;
}

// Hilfsfunktion: Gibt die int-Liste auf der Konsole aus
void print_list(Node *head)
{
    printf("[");
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        printf("%d", curr->value);
        if (curr->next != NULL)
            printf(", ");
    }
    printf("]\n");
}

// Hilfsfunktion: Speicher freigeben
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

Node *process_instructions(Instruction *instructions, int length)
{
    // TODO: Gehe das Array 'instructions' (Länge: 'length') durch
    // und füge die Werte entsprechend FRONT oder BACK in die Liste ein.
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < length; i++)
    {
        Instruction ins = instructions[i];
        Node *new = new_node(ins.value);

        if (head == NULL)
        {
            head = new;
            tail = new;
        }
        else
        {
            if (ins.pos == FRONT)
            {
                new->next = head;
                head = new;
            }

            if (ins.pos == BACK)
            {
                tail->next = new;
                tail = new;
            }
        }
    }

    return head;
}

void test_process_instructions(void)
{
    // Test 1: Beispiel aus der Aufgabenstellung (BACK 5, FRONT 1, FRONT 3 -> [3, 1, 5])
    Instruction inst1[] = {
        {BACK, 5},
        {FRONT, 1},
        {FRONT, 3}};
    Node *l1 = process_instructions(inst1, 3);
    printf("Liste 1: ");
    print_list(l1);

    if (l1 != NULL)
    {
        test_equal_i(l1->value, 3);
        test_equal_i(l1->next->value, 1);
        test_equal_i(l1->next->next->value, 5);
        test_equal_b(l1->next->next->next == NULL, true);
    }
    free_list(l1);

    // Test 2: Nur BACK-Anweisungen (1, 2, 3 -> [1, 2, 3])
    Instruction inst2[] = {
        {BACK, 1},
        {BACK, 2},
        {BACK, 3}};
    Node *l2 = process_instructions(inst2, 3);
    printf("Liste 2: ");
    print_list(l2);
    if (l2 != NULL)
    {
        test_equal_i(l2->value, 1);
        test_equal_i(l2->next->value, 2);
        test_equal_i(l2->next->next->value, 3);
    }
    free_list(l2);

    // Test 3: Leeres Array (length = 0)
    Node *l3 = process_instructions(NULL, 0);
    test_equal_b(l3 == NULL, true);
    free_list(l3);
}

int main(void)
{
    test_process_instructions();
    return 0;
}