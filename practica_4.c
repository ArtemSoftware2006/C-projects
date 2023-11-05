#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

int main()
{
    char *locale = setlocale(LC_ALL, "ru_RU.utf8");

    int numberColumn = 5;
    int numberRow = 5;
    int array[numberRow][numberColumn];
    int deletedValues[numberRow][numberColumn];

    printf("7. Заменить все повторяющиеся числа в строке и столбце на 0.\n");

    for (int i = 0; i < numberRow; i++)
    {
        for (int j = 0; j < numberColumn; j++)
        {
            deletedValues[i][j] = 0;
        }
    }

    printf("Заполните массив :\n");

    for (int i = 0; i < numberRow; i++)
    {
        for (int j = 0; j < numberColumn; j++)
        {
            scanf("%d", &array[i][j]);
        }
        printf("\n");
    }

    printf("\nВведенный массив имеет вид : \n");

    for (int i = 0; i < numberRow; i++)
    {
        for (int j = 0; j < numberColumn; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numberRow; i++)
    {
        for (int j = 0; j < numberColumn; j++)
        {
            for (int k = 0; k < numberColumn; k++)
            {
                if (array[i][j] > 0 && array[i][j] == array[i][k] && k != j)
                {
                    deletedValues[i][j] = 1;
                }
            }
            for (int k = 0; k < numberRow; k++)
            {
                if (array[i][j] > 0 && array[i][j] == array[k][j] && k != i)
                {
                    deletedValues[i][j] = 1;
                }
            }
        }
    }

    printf("\nРезултат обнуления повторяющихся в одном столбце или строке чисел : \n");

    for (int i = 0; i < numberRow; i++)
    {
        for (int j = 0; j < numberColumn; j++)
        {
            if (deletedValues[i][j] == 0)
                printf("%d ", array[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    return 0;
}