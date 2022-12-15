/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:06:03 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/05 09:27:44 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	next(char const *s1, char const *set, size_t i, int x)
{
	size_t	y;

	y = 0;
	if (x == 0)
	{
		while (set[y])
		{
			if (s1[i] == set[y])
				return (1);
			y++;
		}
	}
	else if (x == 1)
	{
		while (set[y])
		{
			if (s1[i] == set[y])
				return (1);
			y++;
		}
	}
	return (0);
}

static size_t	tl(char const *s1, char const *set)
{
	size_t	i;
	size_t	y;
	size_t	x;

	i = ft_strlen(s1);
	x = 0;
	while (i != 0)
	{
		y = 0;
		while (set[y])
		{
			if (s1[i] == set[y] && next(s1, set, i, 1) == 1)
			{
				x++;
				y++;
				break ;
			}
			y++;
		}
		if (next(s1, set, (i - 1), 1) == 0)
			break ;
		i--;
	}
	return (x);
}

static size_t	tf(char const *s1, char const *set)
{
	size_t	i;
	size_t	y;
	size_t	x;

	i = 0;
	x = 0;
	while (s1[i])
	{
		y = 0;
		while (set[y])
		{
			if (s1[i] == set[y] && next(s1, set, i, 0) == 1)
			{
				x++;
				y++;
				break ;
			}
			y++;
		}
		if (next(s1, set, (i + 1), 0) == 0)
			break ;
		i++;
	}
	return (x);
}

static int	test_blank(char const *s1, char const *set)
{
	int	i;
	int	y;

	i = 0;
	while (s1[i])
	{
		y = 0;
		while (set[y])
		{
			if (set[y] == s1[i])
				break ;
			else if (set[y + 1] == '\0')
				return (1);
			y++;
		}
		i++;
	}
	if (set[0] == '\0')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	y;
	size_t	x;
	char	*s;

	if (!s1 || !set)
		return (NULL);
	if (test_blank(s1, set) == 0)
	{
		s = malloc(1);
		s[0] = '\0';
		return (s);
	}
	x = ((ft_strlen(s1)) - (tf(s1, set) + tl(s1, set)));
	s = malloc((x + 1) * sizeof(char));
	if (!s)
		return (NULL);
	y = tf(s1, set);
	x = 0;
	while (x < ft_strlen(s1) - (y + tl(s1, set)))
	{
		s[x] = s1[x + y];
		x++;
	}
	s[x] = '\0';
	return (s);
}
