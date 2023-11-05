#include <stdio.h>   
#include <locale.h>
#include <windows.h>
#include <math.h>

int main()                      
{        
    char *locale = setlocale(LC_ALL, "ru_RU.utf8");

    int number = 0;
    float multy = 0.0;
    float result = 0.0;

    printf("7. Найти среднее геометрическое всех чисел в массиве.\n");

    printf("Введите количество чисел: \n");
    scanf("%d", &number);

    float numbers[number];

    printf("Заполните массив:\n");      
    
    for (int i = 0; i < number; i++)
    {
        scanf("%f", &numbers[i]);
        if (numbers[i] < 0)
        {
            printf("Все значения должны быть больше 0");
            return 0;
        }
    }

    for(int i=0; i < number; i++)
    {   
        multy += numbers[i];   
    }

    result = multy / number;

    printf("Среднее геометрическое всех чисел в массиве: %f", result);

    return 0;                       
}  