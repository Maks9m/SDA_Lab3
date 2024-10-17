#include <stdio.h>

void makeMatrix(int b, float a[b][b]);

int main(void)
{
    int n;
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
    printf("Задана матриця: \n");
    makeMatrix(n, matrix);
    

    float a = 0;//Перший додатній член побічної діагоналі
    int ai = -1, aj = -1;//Рядок, стовпець;
    float b = 0;//Останній відʼємний член побічної діагоналі
    int bi = -1, bj = -1;//Рядок, стовпець;
    for (int i = 0; i < n; i++)
    {
        if(matrix[n-i-1][i] > 0)
        {
            if(a == 0)
            {
                a = matrix[n-i-1][i];
                ai = n - i - 1;
                aj = i;
            }
        }
        if(matrix[n-i-1][i] < 0)
        {
            b = matrix[n-i-1][i];
            bi = n - i - 1;
            bj = i;
        }
    }
    
    // Swap only if valid indices were found
    if (ai != -1 && aj != -1 && bi != -1 && bj != -1)
    {
        matrix[ai][aj] = b;
        matrix[bi][bj] = a;
    }
    printf("Змінена матриця a=%f (ai aj) = (%d, %d) b=%f (bi bj) = (%d, %d): \n", a, ai, aj, b, bi, bj);
    makeMatrix(n, matrix);

}

void makeMatrix(int b, float a[b][b])
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}