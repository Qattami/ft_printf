/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:32:15 by iqattami          #+#    #+#             */
/*   Updated: 2023/12/04 18:49:18 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
