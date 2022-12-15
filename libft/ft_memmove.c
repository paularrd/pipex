/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:24:14 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/05 09:33:54 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_str;
	char	*src_str;

	if (!dest && !src)
		return (NULL);
	dest_str = (char *)dest;
	src_str = (char *)src;
	if (dest_str < src_str)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			dest_str[n - 1] = src_str[n - 1];
			n--;
		}
	}
	return (dest);
}
