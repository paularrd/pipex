/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:04:27 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/07 10:19:40 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child(t_pipex *pipex, char **env)
{
	dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	dup2(pipex->infile, 0);
	close(pipex->fd[1]);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	execve(pipex->function_1, pipex->params_function_1, env);
	ft_fprintf(2, "%s: command not found\n", pipex->function_1);
	free_all(pipex);
	close(0);
	close(1);
	close(2);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	exit(127);
}

void	second_child(t_pipex *pipex, char **env)
{
	dup2(pipex->fd[0], 0);
	close(pipex->fd[1]);
	dup2(pipex->outfile, 1);
	close(pipex->fd[0]);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	else
		return ;
	execve(pipex->function_2, pipex->params_function_2, env);
	ft_fprintf(2, "%s: command not found\n", pipex->function_2);
	free_all(pipex);
	close(0);
	close(1);
	close(2);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	exit(127);
}

void	close_fd(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	close(0);
	close(1);
	close(2);
}

void	wait_fork(t_pipex *pipex)
{
	int		status;

	status = 0;
	close_fd(pipex);
	if (pipex->pid1 != 0)
		waitpid(pipex->pid1, 0, 0);
	if (pipex->pid2 != 0)
		waitpid(pipex->pid2, &status, 0);
	free_all(pipex);
	if (pipex->check2 == 0)
		exit(1);
	exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **env)
{
	t_pipex		pipex;
	int			tmp;

	if (argc != 5)
	{
		ft_fprintf(2, "Error\nNo-valid argument\n");
		return (1);
	}
	initialize(argv, env, &pipex);
	tmp = pipe(pipex.fd);
	if (tmp < 0)
		ft_error("pipe");
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		ft_error("pipex.pid1");
	if (pipex.pid1 == 0)
		pipex.pid2 = -10;
	if (pipex.pid1 == 0 && pipex.pid2 != 0 && pipex.check == 1)
		first_child(&pipex, env);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		ft_error("pipex.pid2");
	if (pipex.pid2 == 0 && pipex.pid1 != 0 && pipex.check2 == 1)
		second_child(&pipex, env);
	wait_fork(&pipex);
}
