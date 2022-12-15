/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:25:32 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/05 11:56:24 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	malloc_error(char **splited, size_t i)
{
	size_t	y;

	y = 0;
	while (y < i)
	{
		free(splited[y]);
		y++;
	}
	free(splited);
}

static size_t	nb_str(char const *s, char c)
{
	size_t	i;
	size_t	x;

	if (!s[0])
		return (0);
	i = 0;
	x = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			x++;
		}
		if (s[i])
			i++;
	}
	if (s[i - 1] != c)
		x++;
	return (x);
}

static size_t	nb_char(char const *s, char c, size_t i)
{
	size_t	y;
	size_t	x;
	size_t	z;

	y = 0;
	z = 0;
	x = 0;
	while (s[y] == c)
		y++;
	while (s[y])
	{
		if (s[y] != c)
		{
			while (s[y] != c && s[y])
			{
				if (z == i)
					x++;
				y++;
			}
			z++;
		}
		if (s[y] != '\0')
			y++;
	}
	return (x);
}

static void	fill_tab(const char *s, char c, size_t i, char *str)
{
	size_t	y;
	size_t	x;
	size_t	z;

	y = 0;
	z = 0;
	x = 0;
	while (s[y])
	{
		if (s[y] != c)
		{
			if (z == i)
			{
				while (s[y] != c && s[y])
					str[x++] = s[y++];
				str[x] = '\0';
			}
			while (s[y] != c && s[y])
				y++;
			z++;
		}
		if (s[y] != '\0')
			y++;
	}
}

char	**ft_split(char const *s, char c)
{
	char		**splited;
	size_t		i;
	size_t		x;

	if (!s)
		return (NULL);
	x = nb_str(s, c);
	splited = malloc((x + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	i = 0;
	while (i < x)
	{
		splited[i] = malloc((nb_char(s, c, i) + 1) * sizeof(char));
		if (!splited[i])
		{
			malloc_error(splited, i);
			return (NULL);
		}
		fill_tab(s, c, i, splited[i]);
		i++;
	}
	splited[i] = NULL;
	return (splited);
}
