/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:43:25 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/24 17:40:55 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == '%')
		i += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		i += ft_puthexa(va_arg(args, long), "0123456789abcdef");
	else if (c == 'X')
		i += ft_puthexa(va_arg(args, long), "0123456789ABCDEF");
	else if (c == 'p')
		i += ft_putnbr_base_pointer(va_arg(args, long), "0123456789abcdef");
	else if (c == 'u')
		i += ft_putnbr_unsigned(va_arg(args, unsigned int));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	count;

	va_list(args);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_parse(args, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
// int main()
// {
// 	#include <stdio.h>
	
// 	char c1 = 'a';
// 	char c2 = 'a';
	
// 	ft_printf("%c%c\n", c1 , c2);
// 	printf("%c%c", c1 , c2);
// }