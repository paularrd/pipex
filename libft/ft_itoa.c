/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:29:40 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/05 12:03:31 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_str(char *int_nbr, int n, int y)
{
	if (n >= 10)
	{
		putnbr_str(int_nbr, n / 10, y - 1);
		putnbr_str(int_nbr, n % 10, y);
	}
	else
		int_nbr[y - 1] = (n + '0');
}

static char	*int_min(void)
{
	char	*str;

	str = ft_strdup("-2147483648");
	return (str);
}

static int	int_malloc(int n)
{
	int	i;
	int	s;

	i = 0;
	s = n;
	while (s >= 10)
	{
		i++;
		s /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		s;
	int		y;
	char	*int_str;

	y = 1;
	if (n == -2147483648)
	{
		int_str = int_min();
		return (int_str);
	}
	if (n < 0)
		n *= -y;
	else
		y = 0;
	int_str = malloc((int_malloc(n) + y + 2) * sizeof(char));
	if (!int_str)
		return (NULL);
	if (y == 1)
		int_str[0] = '-';
	putnbr_str(int_str, n, int_malloc(n) + y + 1);
	s = 0;
	while (s < (int_malloc(n) + y + 1))
		s++;
	int_str[s] = '\0';
	return (int_str);
}
