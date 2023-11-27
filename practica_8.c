#include <stdio.h>
#include <locale.h>
#include <math.h>

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
        length--;
        return *arr * multyOfArray(arr + 1, length);
    }
    return 1;
    
} 

int main() {
    char *locale = setlocale(LC_ALL, "ru_RU.utf8");

    int length = 8;
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 10};

    //pow(number, 1/n) - корень n-ой степени из nгmber
    float gemetricalProgression = pow(multyOfArray(arr, length), 1.0 / length);

    printf("Ответ : %f", gemetricalProgression);

    return 0;
}