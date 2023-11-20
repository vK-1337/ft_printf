/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:49:33 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/19 15:01:52 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *s);
int	ft_putchar(char c);

int	ft_putnbr(int nbr);
int	ft_putnbr_base(unsigned long nbr, char *base);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_base_pointer(unsigned long num, char *base);
int	ft_putnbr_b(unsigned long nb, char *base);
int	ft_puthexa(unsigned int nb, char *base);

int	ft_is_valid(char *base);

#endif