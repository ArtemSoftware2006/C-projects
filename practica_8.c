#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

//8. Найти среднее геометрическое всех чисел в массиве.
//
//  Косвенная рекурсия
//  Прямая рекурсия
//  Обратная 
//  Параллельная
//  Хвостовая

// Вывести
//   Массив вывести рекурсивно
//   Сделать что-то ещё рекусивно

//Произведение элементов массива рекурсивно
int multyOfArray(int *arr, int length) {
    if (length == 0)
    { 
        return 1;
    }
    length--;
    return *arr * multyOfArray(arr + 1, length);;
} 
//Функция с хвостовой рекурсией
int multyOfArrayTail(int *arr, int length, int result) {
    if (length == 0) {
        return result;
    }
    return multyOfArrayTail(arr + 1, length - 1, result * (*arr));
}

//Рекурсивный вывод массива
void printArray(int *arr, int length) {
    if (length != 0) {
        printf("%d ", arr[length - 1]);
        printArray(arr, length - 1);
    }
}

//Рекурсивный подсчёт среднего геометрического 
int multyOfArrayTailFunc(int *arr, int length, bool isEnd) {
    if (length == 0)
    { 
        return 1;
    }

    int tmp = *arr * multyOfArrayTailFunc(arr + 1, length - 1, false);

    if(isEnd == true) {
        printf("\nmultyOfArrayTailFunc : %f\n", pow(tmp, 1.0 / length));
    }
    return tmp;
}

int main() {
    char *locale = setlocale(LC_ALL, "ru_RU.utf8");

    int length = 8;
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 10};

    printArray(arr, length);

    //pow(number, 1/n) - корень n-ой степени из nгmber
    float gemetricalProgression = pow(multyOfArray(arr, length), 1.0 / length);

    printf("\nmultyOfArray : %f", gemetricalProgression);
    
    multyOfArrayTailFunc(arr, length, true);
    gemetricalProgression = pow(multyOfArrayTail(arr, length, 1), 1.0 / length);

    printf("multyOfArrayTail : %f", gemetricalProgression);

    return 0;
}