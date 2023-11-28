#include "prinft.h"

void    ft_format(va_list args ,  char *s, int *nbr)
{

    if (*s == 'c')
    {
        ft_putchar(va_arg(args, int));
        nbr++;
    }
    else if (*s == 's')
        nbr += ft_putstr_fd(va_arg(args, char *));
    else if (*s == 'p')
        return;
    else if (*s == 'd' || *s == 'i')
        nbr += ft_putnbrB(va_arg(args, int), 10, "0123456789");
   else if (*s == 'u')
    return;
    else if (*s == 'x' || *s == 'X')
    {
        if(*s == 'x')
            nbr += ft_putnbrB(va_arg(args,unsigned int), 16, HEX_LOWER);
        else if(*s == 'X')
            nbr += ft_putnbrB(va_arg(args,unsigned int), 16, HEX_LOWER);
    }
    else
    {
    ft_putchar(va_arg(args, int));
    nbr++;
    }
}

int ft_printf(const char *s, ...)
{
    va_list ap;
    int nbr;

    nbr = 0;
    va_start(ap, s);
    while(s)
    {
        if(*s == '%')
        {
            s++;
            if(!(*s))
                break;
            ft_format(ap, *s, &nbr);
        }
        else 
        {
            ft_putchar(*s);
            nbr++;
        }
        s++;
    }
    va_end(ap);
    return (nbr);
}