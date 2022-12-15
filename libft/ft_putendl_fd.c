/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:03:53 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/01 13:18:56 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return (-1);
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
	return (ft_strlen(s));
}
