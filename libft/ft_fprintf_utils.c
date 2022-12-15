/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:06:25 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/26 11:45:48 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_fprint_char(int fd, va_list arguments)
{
	char	c;

	c = va_arg(arguments, int);
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_fprint_nbr(int fd, va_list arguments, char c)
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
		y = ft_putnbr_base_fd(i, "0123456789", fd);
	else if (c == 'u')
		y = ft_putnbr_base_fd(u, "0123456789", fd);
	else if (c == 'x')
		y = ft_putnbr_base_fd(u, "0123456789abcdef", fd);
	else if (c == 'X')
		y = ft_putnbr_base_fd(u, "0123456789ABCDEF", fd);
	return (y);
}

int	ft_fputaddr(int fd, va_list arguments)
{
	long long unsigned int	u;
	int						i;

	u = va_arg(arguments, long long int);
	if (!u)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	else
	{
		write(fd, "0x", 2);
		i = ft_putnbr_base_fd(u, "0123456789abcdef", fd);
	}
	return (i + 2);
}

int	ft_fputper(int fd)
{
	write(fd, "%", 1);
	return (1);
}

int	ft_fprint_str(int fd, va_list arguments)
{
	char	*str;
	int		i;

	str = va_arg(arguments, char *);
	i = ft_putstr_fd(str, fd);
	return (i);
}
