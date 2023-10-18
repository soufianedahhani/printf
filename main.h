#ifndef MAIN_H
#define MAINN_H
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int printf_string(va_list args);
int printf_char(va_list args);
int printf_37(va_list args) ;
int printf_int(va_list args);

int my_printf(const char* format, ...);

#endif
