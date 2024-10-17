#include <stdio.h>

int n;
void makeMatrix(float a[n][n]);

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
    //printf("Ваша матриця: \n");
    //makeMatrix(matrix);
    

    float a = 0;//Перший додатній член побічної діагоналі
    int ai, aj = 0;//Рядок, стовпець;
    float b = 0;//Останній відʼємний член побічної діагоналі
    int bi, bj = 0;//Рядок, стовпець;
    for (int i = 0; i < n; i++)
    {
        if(matrix[n-i][i] > 0)
        {
            if(a == 0)
            {
                a = matrix[n-i][i];
                ai = n - i;
                aj = i;
            }
        }
        if(matrix[n-i][i] < 0)
        {
            b = matrix[n-i][i];
            bi = n - i;
            bj = i;
        }
    }
    
    matrix[ai][aj] = b;
    matrix[bi][bj] = a;
    printf("Змінена матриця: \n");
    makeMatrix(matrix);

}

void makeMatrix(float a[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
}