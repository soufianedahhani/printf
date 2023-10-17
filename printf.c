#include "main.h"
/**
 * Custom printf function that supports character ('c') and string ('s') format specifiers.
 * Prints the formatted output to the standard output.
 * Returns the total number of characters printed.
 */
int my_printf(const char* format, ...)
{
    va_list args;
    va_start(args, format); // Initialize the variable arguments

    int count = 0; // Variable to keep track of the character count

    for (int i = 0; format[i] != '\0'; ++i) {
        if (format[i] == '%') {
            // Handle format specifiers
            ++i;
            if (format[i] == 'c') {
                // Character format specifier
                int c = va_arg(args, int); // Get the character argument from the variable arguments
                write(STDOUT_FILENO, &c, 1); // Write the character to the standard output
                ++count; // Increment the character count
            } else if (format[i] == 's') {
                // String format specifier
                const char* s = va_arg(args, const char*); // Get the string argument from the variable arguments
                int len = 0;
                while (s[len] != '\0')
                    ++len;
                write(STDOUT_FILENO, s, len); // Write the string to the standard output
                count += len; // Increment the character count by the length of the string
            } else {
                // Invalid format specifier
                write(STDOUT_FILENO, "%", 1); // Write '%' character
                write(STDOUT_FILENO, &format[i], 1); // Write the invalid format specifier
                count += 2; // Increment the character count by 2 (for '%' and the invalid specifier)
            }
        } else {
            // Regular character
            write(STDOUT_FILENO, &format[i], 1); // Write the character to the standard output
            ++count; // Increment the character count
        }
    }

    va_end(args); // Clean up the variable arguments

    return count; // Return the total number of characters printed
}
