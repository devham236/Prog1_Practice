#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool are_matrices_equal(int rows, int cols, const double a[rows][cols], const double b[rows][cols])
{
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            double val_a = a[i][j];
            double val_b = b[i][j];

            if(val_a != val_b){
                return false;
            }
        }
    }

    return true; 
}

int main(void)
{
    int rows = 2;
    int cols = 3;

    // Testdaten
    double m1[2][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}};

    double m2[2][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}};

    double m3[2][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 9.9} // Unterscheidet sich am Ende
    };

    // Tests ausführen
    if (are_matrices_equal(rows, cols, m1, m2))
    {
        printf("m1 und m2 sind gleich! (Erwartet)\n");
    }
    else
    {
        printf("m1 und m2 sind unterschiedlich!\n");
    }

    if (are_matrices_equal(rows, cols, m1, m3))
    {
        printf("m1 und m3 sind gleich!\n");
    }
    else
    {
        printf("m1 und m3 sind unterschiedlich! (Erwartet)\n");
    }

    return 0;
}