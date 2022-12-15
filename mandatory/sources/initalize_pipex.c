/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize_pipex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:08:55 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/07 10:29:18 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	open_file(char *file_1, char *file_2, t_pipex *pipex)
{
	pipex->check = 1;
	pipex->check2 = 1;
	pipex->infile = open(file_1, O_RDONLY);
	if (pipex->infile < 0)
	{
		ft_fprintf(2, "bash: ");
		perror(file_1);
		pipex->check = 0;
	}
	pipex->outfile = open(file_2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile < 0)
	{
		ft_fprintf(2, "bash: ");
		perror(file_2);
		pipex->check2 = 0;
	}
}

void	initialize_pipex(char **env, t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 3) == 0)
			pipex->path_env = ft_split(&env[i][5], ':');
		i++;
	}
	i = 0;
	while (pipex->path_env[i])
	{
		tmp = pipex->path_env[i];
		pipex->path_env[i] = ft_strjoin(tmp, "/");
		free(tmp);
		i++;
	}
}

void	initialize(char **argv, char **env, t_pipex *pipex)
{
	open_file(argv[1], argv[4], pipex);
	initialize_pipex(env, pipex);
	get_params(pipex, argv);
	find_first_function(pipex);
	find_second_function(pipex);
}
