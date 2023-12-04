#include "ft_printf.h"


int ft_adress(va_list args, const char *symbol)
{
    int nbr;
    void *ptr;

    ptr = va_arg(args, void *);
    nbr = 0;
    if ((int *)ptr == 0)
    {
        (nbr) += ft_putstr("(nil)");
        return (nbr);
    }
    nbr += ft_putstr("0x");
    nbr += ft_putnbrB((unsigned long int)ptr, 16, symbol);
    return nbr;
}

int ft_putnbrB(unsigned long int n, int base, const char *symbol)
{
    int nbr;

    nbr = 0;
    if(n < 16)
    {
        nbr += ft_putchar(symbol[n]);
    }
    else
    {
        nbr += ft_putnbrB((n / base),base, symbol);
        nbr += ft_putnbrB((n % base), base, symbol);
    }
    return (nbr);
}

void ft_format(va_list args, const char *s, int *nbr)
{
    if (*s == 'c')
    {
       (*nbr) += ft_putchar(va_arg(args, int));

    }
    else if (*s == 's')
    {
            (*nbr) += ft_putstr(va_arg(args, char *));
    }
    else if (*s == 'p')
             (*nbr) += ft_adress(args,HEX_LOWER);
    else if (*s == 'd' || *s == 'i')
        (*nbr) += ft_putnbr(va_arg(args, int));
    else if (*s == 'u')
        (*nbr) += ft_putnbr(va_arg(args, unsigned int));
    else if (*s == 'x' || *s == 'X')
    {
        if (*s == 'x')
            (*nbr) += ft_putnbrB(va_arg(args, unsigned int), 16,"0123456789abcdef");
        else if (*s == 'X')
            (*nbr) += ft_putnbrB(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
    }
    else if (*s == '%')
    {
        ft_putchar(*s);
        (*nbr)++;
    }

}

int ft_printf(const char *s, ...)
{
    va_list ap;
    int nbr;

    nbr = 0;
    va_start(ap, s);
    while (*s != '\0')
    {
        if (*s == '%')
        {
            s++;
            if (!(*s))
                break;
            ft_format(ap, s, &nbr);
        }
        else
        {
            nbr += ft_putchar(*s);
        }
        s++;
    }
    va_end(ap);
    return nbr;
}

// int main ()
// {
//     ft_printf("%p",10);
// }