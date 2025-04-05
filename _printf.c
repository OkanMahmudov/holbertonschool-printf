#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    const char *ptr;
    char c;
    char *str;

    va_start(args, format); // Инициализация списка аргументов

    // Проходим по строке формата
    for (ptr = format; *ptr != '\0'; ptr++) 
    {
        if (*ptr == '%' && (*(ptr + 1) == 'c' || *(ptr + 1) == 's' || *(ptr + 1) == '%')) 
        {
            // Обрабатываем спецификатор '%c'
            if (*(ptr + 1) == 'c') {
                c = va_arg(args, int); // Получаем символ
                putchar(c);
                printed_chars++;
            }
            // Обрабатываем спецификатор '%s'
            else if (*(ptr + 1) == 's') {
                str = va_arg(args, char*); // Получаем строку
                fputs(str, stdout); // Выводим строку
                printed_chars += strlen(str);
            }
            // Обрабатываем спецификатор '%%'
            else if (*(ptr + 1) == '%') {
                putchar('%');
                printed_chars++;
            }
            ptr++; // Пропускаем символ после '%' (например, 'c', 's' или '%')
        } 
        else {
            putchar(*ptr); // Просто выводим символ
            printed_chars++;
        }
    }

    va_end(args); // Завершаем работу с переменными аргументами
    return printed_chars; // Возвращаем количество напечатанных символов
}

