#include <stdio.h>   
#include <locale.h>
#include <windows.h>
#include <stdlib.h>

//7. Определить, является ли произведение двух чисел двузначным числом;   
int main(void)                      
{        
    char *locale = setlocale(LC_ALL, "ru_RU.utf8");

    int num_1, num_2, result = 0;      

    printf("7. Определить, является ли произведение двух чисел двузначным числом;  \n"); 

    printf("Введите первое число : ");
    scanf("%d", &num_1);

    printf("Введите второе число : ");
    scanf("%d", &num_2);

    result = num_1 * num_2;

    printf("Произведение чисел : %d * %d = %d \n", num_1, num_2, result);
    
    printf("Идёт анализ\n");

    for (int i = 0; i <= 100; i++)
    {
        int j = 100 - i;

        for (int g = 0; g < i; g++)
        {
            printf("#");
        }

        for (int k = 0; k < j; k++)
        {
            printf(" ");
        }
        
        printf(" %d",i);
        printf("%% |");

        Sleep(1);
        
        if (i != 100)
            printf("\33[2K\r");
    }
    

    if(abs(result) % 100 >= 10 && abs(result) % 100 < 100 && abs(result) / 100 <= 0)
    {
        printf("\nПроизведение числе %d * %d : является двузначным числом", num_1, num_2);
        printf("\nДа, двузначное");
    }
    else
    {
        printf("\nПроизведение числе %d * %d : НЕ является двузначным числом", num_1, num_2);
        printf("\nНет, НЕ двузначное");
    }
    return 0;                       
}  