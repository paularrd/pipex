/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:26:15 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/06 15:55:33 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	read_input(char *delimiter, int *fd)
{
	char	*tmp_join;
	char	*tmp;

	tmp_join = ft_strjoin(delimiter, "\n");
	while (1)
	{
		close(fd[0]);
		ft_fprintf(1, "> ");
		tmp = get_next_line_zero();
		if (strcmp(tmp, tmp_join) == 0)
		{
			free(tmp);
			free(tmp_join);
			close(fd[1]);
			close(0);
			close(1);
			close(2);
			exit(EXIT_SUCCESS);
		}
		ft_fprintf(fd[1], "%s", tmp);
		free(tmp);
	}
}

void	read_heredoc(t_pipex *pipex, char *delimiter)
{
	int		fd[2];
	int		i;
	int		pid;

	pipex->check = 1;
	i = pipe(fd);
	if (i == -1)
		ft_error("pipe");
	pid = fork();
	if (pid == 0)
		read_input(delimiter, fd);
	else
	{
		close(fd[1]);
		pipex->infile = fd[0];
		wait(NULL);
	}
}

void	get_num_cmd(t_pipex *pipex, int argc)
{
	int		i;

	i = argc - 3;
	pipex->n_cmd = i;
	pipex->pid = ft_calloc((i + 1), sizeof(int));
	if (!pipex->pid)
		exit(EXIT_FAILURE);
}
