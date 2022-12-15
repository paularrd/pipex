/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:21:15 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/03 14:05:48 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_c(int c)
{
	while (c > 127)
		c -= 128;
	return (c);
}

static int	ft_int_y(char const *s, int c)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] == c)
			y++;
		i++;
	}
	return (y);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	y;
	int	x;

	c = ft_int_c(c);
	y = ft_int_y(s, c);
	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			x++;
		if (s[i] == c && x == y)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
