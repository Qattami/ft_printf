#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

#define HEX_LOWER "0123456789abcdef"
#define HEX_UPPER "0123456789ABCDEF"

int ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putnbr(long long n);
int ft_putnbrB(unsigned long int n, int base, const char *symbol);
int	ft_putstr(char *s);


#endif