
#include "printf.h"

int ft_putnbrB(long long n, int base, const char *symbol)
{
    int nbr;

    nbr = 0;
    if (n < 0)
    {
        ft_putchar_fd('-');
        return (ft_puthex(-n, base, symbol)+1);
    }else if(n < 10)
        ft_puthex(symbol[n], base, symbol);
    else
    {
        nbr = ft_puthex((n / base),base, symbol);
        return (nbr + ft_puthex((n % base), base, symbol));
    }
} 