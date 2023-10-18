#include "main.h"
// this method checks the number og charachers on printf and also  print it on stdout 

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i = 0;
    int count = 0;
// here we handle  the  case where we input no argument or one witch is only % following by null byte
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return -1;
    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {// counting the characher before the variable
            write(STDOUT_FILENO, &format[i], 1);
            count++;
        }
        else
        { 
            i++;
            switch (format[i])
            {
                case 'c':
                {
                    char ch = (char)va_arg(args, int);
                    write(STDOUT_FILENO, &ch, 1); count++;
                    break; // displaying the char  we castle the int into char as int can be converted to char 
                }
                case 's' :
                {        const char* s = va_arg(args, const char*); // here we display the string as pointer of char 
             int len = 0;
                while (s[len] != '\0')
                  ++len;

                write(STDOUT_FILENO, s, len);
		count+=len;
                    break;}
                     case 'd':// as int is part of unsigned we treat all on unsigned case
                case 'i':
                {
                    int num = va_arg(args, int);
                    int temp = num;
                    int digits = 0;
                    if (num == 0) {
                        write(STDOUT_FILENO, "0", 1);
                        count++;
                    }
                    else if (num < 0) {//case the number is negative we display - then we make it positive and display it 
                        write(STDOUT_FILENO, "-", 1);
                        count++;
                        temp = -temp;
                    } // this is famous script to count the number of digits
                    while (temp != 0) {
                        temp = temp / 10;
                        digits++;
                    }
                    char buffer[digits]; // here we make the int as table of char by converting it by ASSCI Code
                    for (int j = digits - 1; j >= 0; j--) {
                        buffer[j] = '0' + (num % 10);
                        num = num / 10;
                    }
                    write(STDOUT_FILENO, buffer, digits);
                    count += digits;
                    break;
                }
                default:
                    break;
            }
        }

        i++;
    }

    va_end(args);

    return count;
}

