/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:41:09 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/19 15:01:10 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_b(unsigned int nb, char *base, int size)
{
	long	a;
	int		i;

	a = nb;
	i = 0;
	if (nb < 0)
		a *= -1;
	if (a > size - 1)
	{
		i += ft_puthexa_b(a / size, base, size);
		i += ft_puthexa_b(a % size, base, size);
	}
	else
	{
		write(1, &base[a], 1);
		i++;
	}
	return (i);
}

int	ft_puthexa(unsigned int nbr, char *base)
{
	int	base_size;
	int	i;

	base_size = ft_is_valid(base);
	i = 0;
	if (base_size)
		i += ft_puthexa_b(nbr, base, base_size);
	return (i);
}
