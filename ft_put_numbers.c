/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:57:14 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/19 14:59:55 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	long	n;
	int		i;

	n = nbr;
	i = 0;
	if (n < 0)
	{
		n = -n;
		i += write(1, "-", 1);
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	unsigned long	n;
	int				i;

	n = nbr;
	i = 0;
	if (n < 0)
	{
		n = -n;
		i += write(1, "-", 1);
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}
