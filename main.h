#include <stdio.h>

int _printf(const char *format, ...);

int main(void)
{
    int printed;

    printed = _printf("Hello, %s! Your score is %c.\n", "Alice", 'A');
    printf("Printed %d characters.\n", printed);

    return 0;
}
