//8. Найти среднее геометрическое всех чисел в массиве.

#include <stdio.h>
#include <locale.h>
#include <math.h>
//Произведение элементов массива рекурсивно
int multyOfArray(int *arr, int index, int length) {
    if (index < length)
    { 
        index++;
        return *arr * multyOfArray(arr + 1, index, length);
    }
    return 1;
    
} 

int main() {
    char *locale = setlocale(LC_ALL, "ru_RU.utf8");

    int length = 8;
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 10};

    //pow(number, 1/n) - корень n-ой степени из nгmber
    float gemetricalProgression = pow(multyOfArray(arr, 0, length), 1.0 / length);

    printf("Ответ : %f", gemetricalProgression);

    return 0;
}