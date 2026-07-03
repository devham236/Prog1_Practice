# How to

### Kinder vergleichen

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

### Beim Durchlauf etwas zählen

- Wenn du etwas zählen musst und Eltern und Kind vergleichen musst, solltest du darauf achten das du vor jedem Durchlauf bzw. Test den count in der "nicht recursive" Funktion zurücksetzt
- Deine Abbruchbedingung returned einfach 0 und am Ende der recursive Funktion returns du den count

```c
int count = 0;
int changingSignRecursive(IntTree *node, int value)
{

    if (node == NULL)
    {
        return 0;
    }

    if (node->left != NULL)
    {
        if ((node->left->data < 0 && value > 0) || (node->left->data > 0 && value < 0))
        {
            count++;
        }
    }

    if (node->right != NULL)
    {
        if ((node->right->data < 0 && value > 0) || (node->right->data > 0 && value < 0))
        {
            count++;
        }
    }

    changingSignRecursive(node->left, node->data);
    changingSignRecursive(node->right, node->data);

    return count;
}

int changingSign(IntTree *node)
{
    if (node != NULL)
    {
        count = 0;
        return changingSignRecursive(node, node->data);
    }

    return 0;
}
```
