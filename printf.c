#include "main.h"
typedef struct {
    const char* id;
    int (*f)(va_list);
} convert_match;

int printf_string(va_list args) {
    const char* s = va_arg(args, const char*);
    int len = 0;
    while (s[len] != '\0')
        ++len;
    write(STDOUT_FILENO, s, len);
    return len;
}

int printf_char(va_list args) {
    int c = va_arg(args, int);
    write(STDOUT_FILENO, &c, 1);
    return 1;
}

int printf_37(va_list args) {
    write(STDOUT_FILENO, "%", 1);
    return 1;
}

int printf_int(va_list args) {
    int num = va_arg(args, int);
    char buffer[20];
    int len = sprintf(buffer, "%d", num);
    write(STDOUT_FILENO, buffer, len);
    return len;
}

// Add implementations for other conversion specifiers as needed

int my_printf(const char* format, ...)
{
    convert_match m[] = {
        {"%s", printf_string},
        {"%c", printf_char},
        {"%%", printf_37},
        {"%d", printf_int},
        // Add other conversion specifiers and their corresponding functions here
    };

    va_list args;
    int i = 0, j, len = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return -1;

    while (format[i] != '\0') {
        j = 0;
        while (j < sizeof(m) / sizeof(m[0])) {
            if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1]) {
                len += m[j].f(args);
                i = i + 2;
                break;
            }
            j++;
        }
        if (j == sizeof(m) / sizeof(m[0])) {
            write(STDOUT_FILENO, &format[i], 1);
            len++;
            i++;
        }
    }
    va_end(args);
    return len;
}
