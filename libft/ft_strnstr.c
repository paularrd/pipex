/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:20:31 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/04 15:43:32 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	char	*str;

	str = (char *)big;
	if (len == 0 && (!big || !little))
		return (NULL);
	if (little[0] == '\0')
		return (str);
	i = 0;
	while (str[i] && i < len)
	{
		y = 0;
		while (str[i] == little[y] && i < len)
		{
			if (little[y + 1] == '\0')
				return (str + (i - y));
			i++;
			y++;
		}
		i -= y;
		i++;
	}
	return (NULL);
}
