/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:59:11 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/04 16:08:15 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*s;

	if (size > 2147483647 || nmemb > 2147483647)
		return (NULL);
	else if (size == 0 || nmemb == 0)
	{
		s = malloc(0);
		return (s);
	}
	else if (((size_t)(nmemb * size) / size) != nmemb)
		return (NULL);
	s = malloc((nmemb * size));
	if (!s)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		s[i] = '\0';
		i++;
	}
	return ((void *)s);
}
