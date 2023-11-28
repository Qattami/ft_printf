#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define HEX_LOWER "0123456789abcdef"
#define HEX_UPPER "0123456789ABCDEF"

void	ft_putchar(char c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char *s);
int ft_putnbrB(long long n, int base, const char *symbol);


#endif