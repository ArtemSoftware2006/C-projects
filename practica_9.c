/**
    Лабораторная работа №6
    Тема: Работа с функциями.
    Оформить соответствующие варианты из предыдущих лабораторных работ в виде функций. Не пользоваться глобальными переменными.
    ВНИМАНИЕ! САМОЕ ВАЖНОЕ В РАБОТЕ:
    Необходимо продемонстрировать передачу следующих аргументов в функцию: обычная переменная, одномерный массив,
    двумерный массив, указатель

    Лабораторная работа №9
    Тема: Указатели на функции
    В качестве материала для работы используется соответствующий вариант из лабораторной работы №6.
    Для выполнения работы нужно:
    1. Прописать объявление функции отдельно от её инициализации;
    2. Создать указатели на все используемые функции;
    3. Использовать в работе созданные указатели вместо исходных функций.

    Отдельно необходимо создать массив с функциями с одинаковой сигнатурой и на его основе разработать калькулятор для двух чисел (операции +-).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
//Объявление функции отдельно от реализации
int (Sum)(int, int);
int (Minus)(int, int);
int (Multiply)(int, int);
int (Division)(int, int);
int (GetMax)(int[], int);
void (ResetMaxInAllRows)(int, int, int[][3]);

int main(void)
{
    char *locale = setlocale(LC_ALL, "ru_RU.utf8");

    //Объявление указателя на функцию
    int (*_sum) (int, int) = Sum;
    int (*_GetMax) (int[], int) = GetMax;
    void (*_ResetMaxInAllRows) (int, int, int[][3]) = ResetMaxInAllRows;
    int (*calculate[4]) (int, int) = {Sum, Minus, Multiply, Division};

    int a = 10;
    int b = 20;
    int arr[8] = {1,2,3,5,8,3,79,42};
    int matrix[3][3] = {{1,2,3},{2,3,1},{3,2,1}};

    printf("Сумма чисел %d и %d = %d\n", a, b, _sum(a, b));
    printf("Максимальное значение массива : %d\n", _GetMax(arr, sizeof(arr) / sizeof(arr[0])));

    _ResetMaxInAllRows(3, 3, matrix);

    printf("Обнуление максимов в каждой строке в двумерном массиве : \n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    a = 0; 
    b = 0;
    printf("\nКалькулятор");
    printf("\nВведите числа a и b : ");
    scanf("%d %d", &a, &b);

    int actionNumber = 0;
    printf("\nВыберите действие : \n1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление\n");
    scanf("%d", &actionNumber);

    printf("Ответ : %d\n", calculate[actionNumber - 1](a,b));
    return 0;
}

//Суммирование двух чисел
int Sum(int a, int b) {
    return a + b;
}

//Суммирование двух чисел
int Division(int a, int b) {
    if (b == 0)
    {
        return 0;
    }

    return a / b;
}

//Суммирование двух чисел
int Minus(int a, int b) {
    return a - b;
}

//Суммирование двух чисел
int Multiply(int a, int b) {
    return a * b;
}
//Нахождение максимального числа в массиве
int GetMax(int arr[], int length) {
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
void ResetMaxInAllRows( int n_row, int n_column, int array[][n_column]) {
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
