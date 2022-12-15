/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:10:40 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/01 10:43:05 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	find_first_function(t_pipex *pipex)
{
	int		i;
	int		check_execute;
	char	*join;

	i = 0;
	check_execute = -1;
	while (pipex->path_env[i])
	{
		join = ft_strjoin(pipex->path_env[i], pipex->function_1);
		check_execute = access(join, X_OK);
		if (check_execute == 0)
		{
			free(pipex->function_1);
			pipex->function_1 = join;
			return ;
		}
		free(join);
		i++;
	}
}

void	find_second_function(t_pipex *pipex)
{
	int		i;
	int		check_execute;
	char	*join;

	i = 0;
	check_execute = -1;
	while (pipex->path_env[i])
	{
		join = ft_strjoin(pipex->path_env[i], pipex->function_2);
		check_execute = access(join, X_OK);
		if (check_execute == 0)
		{
			free(pipex->function_2);
			pipex->function_2 = join;
			return ;
		}
		i++;
		free(join);
	}
}

void	get_params(t_pipex *pipex, char **argv)
{
	pipex->params_function_1 = ft_split(argv[2], ' ');
	pipex->params_function_2 = ft_split(argv[3], ' ');
	pipex->function_1 = ft_strdup(pipex->params_function_1[0]);
	pipex->function_2 = ft_strdup(pipex->params_function_2[0]);
}
