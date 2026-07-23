#include "base.h"

/*
Aufgabe: Baum-Traversierung mit String-Anweisungen

Du bekommst die Wurzel eines Binärbaums und einen Anweisungs-String:
- 'l': Gehe zum linken Kind
- 'r': Gehe zum rechten Kind
- 'v': Ersetze den Wert des AKTUELLEN Knotens durch das NÄCHSTE Zeichen im String
       (Beispiel: "vx" -> Das 'v' sagt "ersetzen", das 'x' ist der neue Wert)

Annahme: Der Pfad im String ist valide und führt zu existierenden Knoten.
Die Funktion modifiziert den Baum direkt in-place und gibt den Wurzelknoten zurück.
*/

typedef struct Node
{
    char value;
    struct Node *left;
    struct Node *right;
} Node;

// Hilfsfunktion: Erstellt einen neuen Baumknoten auf dem Heap
Node *new_node(char val)
{
    Node *node = xmalloc(sizeof(Node));
    node->value = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Hilfsfunktion: Gibt den gesamten Baum-Speicher wieder frei
void free_tree(Node *root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Hilfsfunktion: Gibt den Baum in Pre-Order Darstellung aus (hilft beim Debuggen)
void print_tree(Node *root)
{
    if (root == NULL)
    {
        printf(".");
        return;
    }
    printf("%c(", root->value);
    print_tree(root->left);
    printf(",");
    print_tree(root->right);
    printf(")");
}

Node *process_instructions(Node *root, char *instructions)
{
    // TODO: Implementiere die Navigation und das Ersetzen der Knotenwerte!
    Node *curr = root;

    for (int i = 0; instructions[i] != '\0'; i++)
    {
        char c = instructions[i];

        if (c == 'r')
        {
            curr = curr->right;
        }
        else if (c == 'l')
        {
            curr = curr->left;
        }
        else if (c == 'v')
        {
            curr->value = instructions[i + 1];
            i++;
        }
    }

    return root;
}

void test_tree_instructions(void)
{
    // Aufbau eines Testbaums:
    //        'a'
    //       /   \
    //     'b'   'c'
    //     / \
    //   'd' 'e'

    Node *root = new_node('a');
    root->left = new_node('b');
    root->right = new_node('c');
    root->left->left = new_node('d');
    root->left->right = new_node('e');

    printf("Baum VORHER: ");
    print_tree(root);
    printf("\n");

    // Test 1: Wurzel direkt ersetzen ("vx")
    process_instructions(root, "vx");
    test_equal_i(root->value, 'x');

    // Test 2: Nach links gehen und Wert durch 'y' ersetzen ("lvy")
    process_instructions(root, "lvy");
    test_equal_i(root->left->value, 'y');

    // Test 3: Längerer Pfad: Rechts -> links nicht vorhanden, aber z.B. links -> rechts -> 'z' ("lrvz")
    process_instructions(root, "lrvz");
    test_equal_i(root->left->right->value, 'z');

    // Test 4: Komplexe Anweisung "rvy" (Rechts gehen, Wert zu 'y' ändern)
    process_instructions(root, "rvy");
    test_equal_i(root->right->value, 'y');

    printf("Baum NACHHER: ");
    print_tree(root);
    printf("\n");

    // Speicher aufräumen
    free_tree(root);
}

int main(void)
{
    test_tree_instructions();
    return 0;
}