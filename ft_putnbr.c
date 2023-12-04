/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:58:31 by iqattami          #+#    #+#             */
/*   Updated: 2023/12/03 10:39:53 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long n)
{
	unsigned int	nb;
	int nbr;

	nbr = 0;
	nb = n;
	if (n < 0)
	{
		nbr += ft_putchar('-');
		nb = -n;
	}
	if (nb < 10)
		nbr += ft_putchar(nb + 48);
	else
	{
		nbr += ft_putnbr((nb / 10));
		nbr += ft_putnbr((nb % 10));
	}
	return (nbr);
}
