/**
    Лабораторная работа №6
    Тема: Работа с функциями.
    Оформить соответствующие варианты из предыдущих лабораторных работ в виде функций. Не пользоваться глобальными переменными.
    ВНИМАНИЕ! САМОЕ ВАЖНОЕ В РАБОТЕ:
    Необходимо продемонстрировать передачу следующих аргументов в функцию: обычная переменная, одномерный массив,
    двумерный массив, указатель
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, min, counter;

    const int n = 100, m = 100;
    int a[n][m];
    printf("enter number of lines: ");
    scanf("%d", &n);
    printf("enter the number of columns: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            a[i][j] = rand() % 21 - 10;
            printf("a[%d][%d]=%d\n", i + 1, j + 1, a[i][j]);
        }

    for (i = 0; i < n; i++)
    {
        min = a[i][0];
        counter = 0;
        for (j = 0; j < m; j++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
                counter = 1;
            }
            else if (a[i][j] == min)
                counter++;
        }
        printf("number of minima in the line %d: %d\n", i + 1, counter);
    }

    for (j = 0; j < m; j++)
    {
        min = a[0][j];
        counter = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
                counter = 1;
            }
            else if (a[i][j] == min)
                counter++;
        }
        printf("number of minimums in a column %d: %d\n", j + 1, counter);
    }
    return 0;
}