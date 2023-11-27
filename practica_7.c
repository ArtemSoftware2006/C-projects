#include <ctype.h>
#include <locale.h>
#include <stdio.h>
//7. Сделать большими только гласные буквы;
//Изучить строковые функции в СИ

//Ищет гласные буквы и переводит их в верхний регистр
void convertVolowesToUpper(char* str) {
    while (*str)
    {
        if (*str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U' || *str == 'Y')
        {
            *str = tolower(*str);
        }
        str++;
    }
    
}

int main() {
    char *locale = setlocale(LC_ALL, "ru_RU.utf8");

    char str[] = "Hello, World!";

    convertVolowesToUpper(str);

    printf("Результат: %s\n", str);

    return 0;
}