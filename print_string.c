#include "holberton.h"

/**
 * _print_string - Prints a string
 * @s: String to print
 *
 * Return: Number of characters printed
 */
int _print_string(char *s)
{
    int len = 0;

    if (s == NULL)
        s = "(null)";

    while (*s)
    {
        len += write(STDOUT_FILENO, s, 1);
        s++;
    }

    return len;
}
