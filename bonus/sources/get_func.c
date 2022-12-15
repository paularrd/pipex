/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:10:40 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/07 11:52:21 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_cmd(char *cmd, char **path)
{
	char	*path_to_cmd;
	int		i;
	int		check_execute;

	i = 0;
	check_execute = -1;
	while (path[i])
	{
		path_to_cmd = ft_strjoin(path[i], cmd);
		check_execute = access(path_to_cmd, X_OK);
		if (check_execute == 0)
			return (path_to_cmd);
		free(path_to_cmd);
		i++;
	}
	return (cmd);
}

int	check_arg(int argc, char **argv)
{
	if (argc < 4)
		return (0);
	if (ft_strcmp(argv[1], "here_doc") != 0 && argc < 5)
		return (0);
	if (ft_strcmp(argv[1], "here_doc") == 0 && argc < 6)
		return (0);
	return (1);
}
