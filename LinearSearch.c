#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void makeMatrix(int b, float a[b][b], int ai, int aj, int bi, int bj);

int main(void)
{
    srand(time(0));
    int n;
    printf("Введіть розмірність квадратної матриці: \n");
    scanf("%i", &n);
    float matrix[n][n];

    int g = 0;// 0 - не генерувати матрицю, 1 - згенерувати матрицю;
    printf("Згенерувати матрицю?\n");
    scanf("%i", &g);
    if(g == 0)//Ввести вручну
    {
        for (int i = 0; i < n; i++)
        {
            printf("Введіть %i рядок\n", i+1 );
            for (int j = 0; j < n; j++)
            {
                scanf("%f", &matrix[i][j]);
            }
        }
    }
    else//Згенерувати матрицю з випадковим числом від -100.0 до 100.0
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = ((float)rand()/(float)(RAND_MAX)) * 200.0 - 100.0;
            }
        }
    }
    

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

    printf("Задана матриця: \n");
    makeMatrix(n, matrix, ai, aj, bi, bj);
    
    // Swap only if valid indices were found
    if (ai != -1 && aj != -1 && bi != -1 && bj != -1)
    {
        matrix[ai][aj] = b;
        matrix[bi][bj] = a;
        printf("Перший додатній член побічної діагоналі = %.2f\n", a);
        printf("Останній відʼємний член побічної діагоналі = %.2f\n\n", b);
        printf("Змінена матриця \n");
        makeMatrix(n, matrix, ai, aj, bi, bj);
    }
    else
    {
        if(ai == -1 && aj == -1 && bi == -1 && bj == -1)
        {
            printf("Шукані елементи не знайдені");
        }
        else
        {
            if(ai == -1 && aj == -1)
            {
                printf("He знайдено перший додатній член побічної діагоналі\n");
                printf("Останній відʼємний член побічної діагоналі = %.2f\n", b);
            }
            else
            {
                printf("He знайдено останній відʼємний член побічної діагоналі\n");
                printf("Перший додатній член побічної діагоналі = %.2f\n", a);
            }
        }
    }
}

void makeMatrix(int b, float a[b][b], int ai, int aj, int bi, int bj)
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < b; j++)
        {
            //Виділення побічної діагоналі
            if(j == b-i-1)
            {
                if(j == aj && i == ai)//Виділити перший додатній член побічної діагоналі
                {
                    printf("\033[1;31m");
                }
                else
                {
                    if(j == bj && i == bi)//Виділити останній відʼємний член побічної діагоналі
                    {
                        printf("\033[1;31m");                
                    }
                    else
                    {
                        printf("\033[1;33m");
                    }
                }
                printf("%7.2f ", a[i][j]);
                printf("\033[0m");//Прибрати колір
            }
            else
            {
                printf("%7.2f ", a[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}