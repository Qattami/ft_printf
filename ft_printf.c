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

int handle_percent(const char *s, int *i, int *nbr)
{
    if(s[*i] == '%' && !s[*i + 1])
        return (-1);
    *nbr += write(1, &s[*i], 1);
    return (0);
}

void ft_format(va_list args, const char *s, int *nbr, int *i)
{
    if (s[*i +1] == '%')
        *nbr += write(1, "%", 1);   
    else if (s[*i +1] == 'c')
       (*nbr) += ft_putchar(va_arg(args, int));
    else if (s[*i +1] == 's')
            (*nbr) += ft_putstr(va_arg(args, char *));
    else if (s[*i +1] == 'p')
             (*nbr) += ft_adress(args,HEX_LOWER);
    else if (s[*i +1] == 'd' || s[*i +1] == 'i')
        (*nbr) += ft_putnbr(va_arg(args, int));
    else if (s[*i +1] == 'u')
        (*nbr) += ft_putnbr(va_arg(args, unsigned int));
    else if (s[*i + 1] == 'x')
        (*nbr) += ft_putnbrB(va_arg(args, unsigned int), 16,"0123456789abcdef");
    else if (s[*i + 1] == 'X')
        (*nbr) += ft_putnbrB(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
    else 
    {
        *nbr += ft_putchar(s[*i +1]);
        *nbr += ft_putchar(s[*i]);
    }
    (*i)++;
}
int ft_printf(const char *s, ...)
{
    va_list ap;
    int nbr;
    int i;

    nbr = 0;
    i = 0;
    va_start(ap, s);
    while (s[i])
    {
        if (s[i] == '%' && s[i+1])
            ft_format(ap, s, &nbr, &i);
        else if(handle_percent(s,&i,&nbr) == -1)
            return(-1);
        i++;
    }
    va_end(ap);
    return nbr;
}

int main ()
{   
     int i;
     int j;
     i = printf("%%%%%%%");
     printf("\n %d", i);
     j = ft_printf("%%%%%%%");
     printf("\n %d", j);
}