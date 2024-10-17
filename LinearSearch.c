#include <stdio.h>

int n;

int main(void)
{
    printf("Введіть розмірність квадратної матриці: \n");
    scanf("%i", &n);
    float matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        printf("Введіть %i рядок\n", i+1 );
        for (int j = 0; j < n; j++)
        {
        scanf("%f", &matrix[i][j]);
        }
    }
}