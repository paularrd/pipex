/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:55:18 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/01 15:10:01 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	n_char(long long int n, char *base)
{
	int		s;

	s = 0;
	if (n < 0)
	{
		s++;
		n *= -1;
	}
	while ((size_t)n >= ft_strlen(base))
	{
		n /= ft_strlen(base);
		s++;
	}
	s++;
	return ((int)s);
}

int	ft_putnbr_base_fd(long long int nb, char *base, int fd)
{
	int		s;

	s = n_char(nb, base);
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if ((size_t)nb >= ft_strlen(base))
	{
		ft_putnbr_base_fd(nb / ft_strlen(base), base, fd);
		ft_putnbr_base_fd(nb % ft_strlen(base), base, fd);
	}
	else
		write(fd, &base[nb], 1);
	return (s);
}
