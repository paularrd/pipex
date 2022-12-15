/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:22:57 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/12/01 11:58:22 by fle-tolg         ###   ########.fr       */
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
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
	int		check;
	int		check2;
	char	*function_1;
	char	*function_2;
	char	**params_function_1;
	char	**params_function_2;
	char	**path_env;
}				t_pipex;

void	ft_error(char *s);
void	close_fd(t_pipex *pipex);
void	free_all(t_pipex *pipex);
void	get_params(t_pipex *pipex, char **argv);
void	first_child(t_pipex *pipex, char **env);
void	second_child(t_pipex *pipex, char **env);
void	initialize(char **argv, char **env, t_pipex *pipex);
void	open_file(char *file_1, char *file_2, t_pipex *pipex);
void	initialize_pipex(char **env, t_pipex *pipex);

void	find_first_function(t_pipex *pipex);
void	find_second_function(t_pipex *pipex);

#endif
