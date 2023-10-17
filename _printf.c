#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i = 0;
    int count = 0;
    
    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
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
                    write(STDOUT_FILENO, &ch, 1);
                    break;
                }
                case 's' :
                {        const char* s = va_arg(args, const char*);
             int len = 0;
                while (s[len] != '\0')
                  ++len;
                    
                write(STDOUT_FILENO, s, len); 
                    break;}
                default:
                    break;
            }
        }
        
        i++;
    }
    
    va_end(args);
    
    return count;
}

int main()
{
    char* y = "test";
    _printf("Hello World %s", y);
    
    return 0;
}
