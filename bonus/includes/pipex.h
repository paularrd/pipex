/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:22:57 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/07 11:50:47 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include  "../../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipex
{
	pid_t	*pid;
	int		fd[2];
	int		infile;
	int		outfile;
	int		check;
	int		check2;
	int		n_cmd;
	char	**path_env;
}				t_pipex;

void	free_all(t_pipex *pipex);
void	ft_error(char *s);
void	initialize(int argc, char **argv, char **env, t_pipex *pipex);
void	get_num_cmd(t_pipex *pipex, int argc);
void	read_heredoc(t_pipex *pipex, char *delimiter);
void	open_output_file(char *file_1, t_pipex *pipex);
void	initialize_pipex(char **env, t_pipex *pipex);
void	open_file(char *file_1, char *file_2, t_pipex *pipex);
void	get_n_pipe(t_pipex *pipex, char **argv);
void	find_first_function(t_pipex *pipex);
void	find_second_function(t_pipex *pipex);
void	get_params(t_pipex *pipex, char *arg1, char *arg2);
void	do_function(t_pipex *pipex, char *cmd, char **env);
void	last_child(t_pipex *pipex, char *cmd, char **env);
void	close_fd(t_pipex *pipex);
void	wait_fork(t_pipex *pipex);
void	close_all_fd(t_pipex *pipex);

int		check_arg(int argc, char **argv);

char	*get_cmd(char *cmd, char **path);

#endif
