/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:46:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/06 14:35:31 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char	*join(char *buf, char *file)
{
	char	*tmp;

	tmp = ft_strjoin(file, buf);
	free(file);
	return (tmp);
}

static char	*malloc_fd(int fd, char *file)
{
	char		*buf;
	int			i;

	if (!file)
		file = ft_calloc(1, sizeof(char));
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(file);
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		file = join(buf, file);
		if (ft_strrchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (file);
}

char	*get_next_line_zero(void)
{
	char		*file;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	file = NULL;
	file = malloc_fd(0, file);
	if (!file)
		return (NULL);
	return (file);
}
