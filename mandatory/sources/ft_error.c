/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:08:46 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/26 14:00:33 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_all(t_pipex *pipex)
{
	free_split(pipex->params_function_1);
	free_split(pipex->params_function_2);
	free_split(pipex->path_env);
	free(pipex->function_1);
	free(pipex->function_2);
}

void	ft_error(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}
