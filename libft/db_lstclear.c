/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:56:07 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/01 12:23:02 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	db_lstclear(t_db_list **lst)
{
	t_db_list		*tmp;

	if (*lst)
	{
		while ((*lst)->prev != NULL)
			*lst = (*lst)->prev;
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			(*lst) = tmp;
		}
		*lst = NULL;
	}
}
