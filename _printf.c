#include "holberton.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int len = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Move past the '%' character */
            /* Handle conversion specifier */
            switch (*format)
            {
                case 's':
                    len += _print_string(va_arg(args, char *));
                    break;
                case 'd':
                    len += _print_int(va_arg(args, int));
                    break;
                default:
                    /* Handle unsupported specifier */
                    len += write(STDOUT_FILENO, "%", 1);
                    if (*format)
                        len += write(STDOUT_FILENO, format, 1);
                    break;
            }
        }
        else
        {
            /* Handle regular characters */
            len += write(STDOUT_FILENO, format, 1);
        }

        format++; /* Move to the next character */
    }

    va_end(args);

    return len;
}
