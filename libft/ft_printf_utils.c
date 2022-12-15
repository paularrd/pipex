/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:06:25 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/13 12:59:37 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_print_char(va_list arguments)
{
	char	c;

	c = va_arg(arguments, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_nbr(va_list arguments, char c)
{
	int					i;
	int					y;
	unsigned int		u;

	if (c == 'i')
		i = va_arg(arguments, int);
	else
		u = va_arg(arguments, unsigned int);
	y = 0;
	if (c == 'i' || c == 'd')
		y = ft_putnbr_base_fd(i, "0123456789", 1);
	else if (c == 'u')
		y = ft_putnbr_base_fd(u, "0123456789", 1);
	else if (c == 'x')
		y = ft_putnbr_base_fd(u, "0123456789abcdef", 1);
	else if (c == 'X')
		y = ft_putnbr_base_fd(u, "0123456789ABCDEF", 1);
	return (y);
}

int	ft_putaddr(va_list arguments)
{
	long long unsigned int	u;
	int						i;

	u = va_arg(arguments, long long int);
	if (!u)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		i = ft_putnbr_base_fd(u, "0123456789abcdef", 1);
	}
	return (i + 2);
}

int	ft_putper(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_print_str(va_list arguments)
{
	char	*str;
	int		i;

	str = va_arg(arguments, char *);
	i = ft_putstr_fd(str, 1);
	return (i);
}
