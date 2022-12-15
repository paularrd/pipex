/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:04:27 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/07 11:48:35 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	do_function(t_pipex *pipex, char *cmd, char **env)
{
	char	**arg;

	arg = ft_split(cmd, ' ');
	cmd = get_cmd(arg[0], pipex->path_env);
	dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	dup2(pipex->infile, 0);
	close(pipex->fd[1]);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	execve(cmd, arg, env);
	ft_fprintf(2, "%s: command not found\n", cmd);
	free_split(arg);
	free_all(pipex);
	close(0);
	close(1);
	close(2);
	exit(127);
}

void	last_child(t_pipex *pipex, char *cmd, char **env)
{
	char	**arg;

	arg = ft_split(cmd, ' ');
	cmd = get_cmd(arg[0], pipex->path_env);
	dup2(pipex->infile, 0);
	close(pipex->fd[1]);
	dup2(pipex->outfile, 1);
	close(pipex->fd[0]);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	execve(cmd, arg, env);
	ft_fprintf(2, "%s: command not found\n", cmd);
	free_split(arg);
	free_all(pipex);
	close(0);
	close(1);
	close(2);
	exit(127);
}

void	loop_function(t_pipex *pipex, char **env, char **argv, int i)
{
	int		y;
	int		tmp;

	y = 2;
	if (ft_strcmp(argv[1], "here_doc") == 0)
		y = 3;
	tmp = pipe(pipex->fd);
	if (tmp < 0)
		ft_error("pipe");
	pipex->pid[i] = fork();
	if (pipex->pid[i] == 0 && pipex->check == 1)
		do_function(pipex, argv[i + y], env);
	else if (pipex->pid[i] == 0 && pipex->check == 0)
		close_all_fd(pipex);
	if (pipex->infile != -1)
		close(pipex->infile);
	close(pipex->fd[1]);
	pipex->infile = pipex->fd[0];
	pipex->check = 1;
}

int	main(int argc, char **argv, char **env)
{
	t_pipex		pipex;
	pid_t		i;
	int			y;

	if (check_arg(argc, argv) == 0)
	{
		ft_fprintf(2, "Error\nNo-valid argument\n");
		return (1);
	}
	i = 0;
	y = argc;
	initialize(argc, argv, env, &pipex);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		y--;
	while (i + 3 < (y - 1))
	{
		loop_function(&pipex, env, argv, i);
		i++;
	}
	pipex.pid[i] = fork();
	if (pipex.pid[i] == -1)
		ft_error("pipex.pid[1]");
	if (pipex.pid[i] == 0 && pipex.check2 == 1)
		last_child(&pipex, argv[argc - 2], env);
	wait_fork(&pipex);
}
