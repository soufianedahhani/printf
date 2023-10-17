#include "holberton.h"

/**
 * _print_int - Prints an integer
 * @n: Integer to print
 *
 * Return: Number of characters printed
 */
int _print_int(int n)
{
    int len = 0;
    int sign = 1;

    if (n < 0)
    {
        len += write(STDOUT_FILENO, "-", 1);
        sign = -1;
    }

    if (n / 10)
        len += _print_int(n / 10);

    len += write(STDOUT_FILENO, &"0123456789"[n % 10 * sign], 1);

    return len;
}
