/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:37:21 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/24 17:42:12 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[i])
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || (base[i] >= 7
				&& base[i] <= 13))
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_putnbr_b(unsigned long nb, char *base)
{
	unsigned long	a;
	unsigned long	size;
	int				i;

	size = ft_is_valid(base);
	a = nb;
	i = 0;
	if (nb < 0)
	{
		a *= -1;
		write(1, "-", 1);
	}
	if (a > size - 1)
	{
		i += ft_putnbr_b(a / size, base);
		i += ft_putnbr_b(a % size, base);
	}
	else
	{
		write(1, &base[a], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	base_size;
	int	i;

	base_size = ft_is_valid(base);
	i = 0;
	if (base_size)
		i += ft_putnbr_b(nbr, base);
	return (i);
}

int	ft_putnbr_base_pointer(unsigned long nbr, char *base)
{
	int				base_size;
	int				i;
	unsigned long	n;

	if (!nbr)
		return (write(1, "(nil)", 5));
	base_size = ft_is_valid(base);
	if (nbr < 0)
		n = -nbr;
	i = 0;
	write(1, "0", 1);
	write(1, "x", 1);
	i += 2;
	if (base_size)
		i += ft_putnbr_base(nbr, base);
	return (i);
}
