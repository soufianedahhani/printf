#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char c;
    char *str;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            count++;
        }
        else
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        count++;
                    }
                    break;
                default:
                    write(1, format - 1, 2);
                    count += 2;
                    break;
            }
        }
        format++;
    }

    va_end(args);

    return count;
}
