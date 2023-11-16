#include <ctype.h>
#include <locale.h>
#include <stdio.h>
//7. Сделать большими только гласные буквы;

//Ищет гласные буквы и переводит их в верхний регистр
void convertVolowesToUpper(char* str) {
    while (*str)
    {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' || *str == 'y')
        {
            *str = toupper(*str);
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