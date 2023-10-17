#include "main.h"

int printf(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; // Variable to keep track of the character count

    for (int i = 0; format[i] != '\0'; ++i) {
        if (format[i] == '%') {
            // Handle format specifiers
            ++i;
            if (format[i] == 'c') {
                // Character format specifier
                int c = va_arg(args, int);
                write(STDOUT_FILENO, &c, 1);
                ++count;
            } else if (format[i] == 's') {
                // String format specifier
                const char* s = va_arg(args, const char*);
                int len = 0;
                while (s[len] != '\0')
                    ++len;
                write(STDOUT_FILENO, s, len);
                count += len;
            } else {
                // Invalid format specifier
                write(STDOUT_FILENO, "%", 1);
                write(STDOUT_FILENO, &format[i], 1);
                count += 2;
            }
        } else {
            // Regular character
            write(STDOUT_FILENO, &format[i], 1);
            ++count;
        }
    }

    va_end(args);

    return count;
}
