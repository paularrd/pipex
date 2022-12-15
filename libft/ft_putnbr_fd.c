/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:04:30 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/01 13:38:52 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_char(int n)
{
	int		s;

	s = 0;
	if (n < 0)
	{
		s++;
		n *= -1;
	}
	if (n >= 10)
	{
		n_char(n / 10);
		n_char(n % 10);
	}
	else
		s++;
	return (s);
}

int	ft_putnbr_fd(int n, int fd)
{
	int		s;
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	s = n_char(n);
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	return (s);
}
