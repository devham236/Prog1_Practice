## How to

- Wenn du zwei Kindknoten vergleichen musst, kannst du eigentlich immer nur ein if aufstellen nach deiner Abbruchbedingung und erstmal überprüfen ob beide nicht null sind und dann das was in der Aufgabe verlangt wird überprüfen:

```c
// Knoten auf der Konsole ausgeben, die sowohl über einen linken, als auch einen rechten
// Nachfolger verfügen und deren rechter Nachfolger größer ist als der linke Nachfolger.
// Nehmen Sie dabei an, dass der Baum unsortiert ist.

void printSorted(IntTree *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL && node->right != NULL && node->left->data < node->right->data)
    {
        printf("%d\n", node->data);
    }

    printSorted(node->left);
    printSorted(node->right);
}
```
