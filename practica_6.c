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
#include <locale.h>
#include <windows.h>
//Суммирование двух чисел
int GetSum(int a, int b) {
    return a + b;
}
//Нахождение максимального числа в массиве
int GetMax(int *arr, int length) {
    int max = 0;
    for (int i = 0; i < length; i++)
    {
        if(*(arr + i) > max) 
        {
            max = *(arr + i);
        }
    }
    return max;
}
//Обнуление максимального значения в каждой строке
void ResetMaxInAllRows( int n_row, int n_column, int array[n_row][n_column]) {
    for (int i = 0; i < n_row; i++) {
        int max = 0;
        int maxIndex = 0;
        for (int j = 0; j < n_column; j++) {
            if(array[i][j] > max) {
                max = array[i][j];
                maxIndex = j;
            }
        }

        array[i][maxIndex] = 0;
    }
}

int main(void)
{
    char *locale = setlocale(LC_ALL, "ru_RU.utf8");

    int a = 10;
    int b = 20;
    int arr[8] = {1,2,3,5,8,3,79,42};
    int matrix[3][3] = {{1,2,3},{2,3,1},{3,2,1}};

    printf("Сумма чисел %d и %d = %d\n", a, b, GetSum(a, b));
    printf("Максимальное значение массива : %d\n", GetMax(arr, sizeof(arr) / sizeof(arr[0])));

    ResetMaxInAllRows(3, 3, matrix);

    printf("Обнуление максимов в каждой строке в двумерном массиве : \n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
}