//7. Нечётные числа из исходного массива.

/*
    Лабораторная работа №5
    Тема работы: Динамическая память.
    Каждая программа должна освобождать динамическую память сразу, как только хранящиеся в ней данные больше не нужны.
    Создать одномерный массив с целыми числами. Составить еще один одномерный массив, который будет содержать только ... из исходного массива:
*/

#include <stdio.h>
#include <stdlib.h>   
#include <math.h>

int main() {

    int const COUNT_NUMBERS = 10;

    int numbers[] = {10, -1, 0, 9, 13, 123, 12, 5, 7, 3};
    // Задаю размер памяти
    int *nechet = malloc(0);

    int counterNechet = 0;

    for (int i = 0; i < COUNT_NUMBERS; i++)
    {
        if (abs(numbers[i] % 2) == 1)
        {
            counterNechet++;
            //Добавление памяти 
            nechet = realloc(nechet, sizeof(int));

            nechet[counterNechet - 1] = numbers[i];
        }
        
    }

    printf("Memory : %d" , counterNechet * sizeof(int));
    printf("\n");

    for (int i = 0; i < counterNechet; i++)
    {
        printf("%d ", nechet[i]);
    }
    //Очищаю память
    free(nechet);
    
}
