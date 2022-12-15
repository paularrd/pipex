/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:46:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/06 14:31:04 by fle-tolg         ###   ########.fr       */
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

static char	*get_line(char *file)
{
	size_t		i;
	size_t		y;
	char		*line;

	i = 0;
	if (file[0] == '\0')
		return (NULL);
	while (file[i] && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	y = 0;
	while (y < i && file[y])
	{
		line[y] = file[y];
		y++;
	}
	line[y] = '\0';
	return (line);
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

static char	*delete_line(char *file)
{
	size_t		i;
	size_t		y;
	char		*left_line;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (file[i] == '\0')
	{
		free(file);
		return (NULL);
	}
	left_line = malloc(((ft_strlen(file) - i)) * sizeof(char));
	if (!left_line)
		return (NULL);
	i++;
	y = 0;
	while (file[i])
		left_line[y++] = file[i++];
	left_line[y] = '\0';
	free(file);
	return (left_line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*file;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = malloc_fd(fd, file);
	if (!file)
		return (NULL);
	line = get_line(file);
	file = delete_line(file);
	return (line);
}
