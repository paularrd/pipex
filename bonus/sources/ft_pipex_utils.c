/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:08:46 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/06 17:04:58 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_all_fd(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close_fd(pipex);
	free_all(pipex);
	close(0);
	close(1);
	close(2);
	exit(1);
}

void	free_all(t_pipex *pipex)
{
	free_split(pipex->path_env);
	free(pipex->pid);
}

void	ft_error(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	close_fd(t_pipex *pipex)
{
	if (pipex->pid[0] != 0)
	{
		close(pipex->fd[0]);
		close(pipex->fd[1]);
	}
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
}

void	wait_fork(t_pipex *pipex)
{
	int		status;
	int		i;

	i = 1;
	status = 1;
	close_fd(pipex);
	waitpid(pipex->pid[i], &status, 0);
	while (pipex->pid[i])
	{
		waitpid(pipex->pid[i], &status, 0);
		i++;
	}
	close(0);
	close(1);
	close(2);
	free_all(pipex);
	if (pipex->outfile == -1)
		exit(1);
	exit(WEXITSTATUS(status));
}
