/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:40:36 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/01 13:45:33 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	db_lstdelone(t_db_list **lst)
{
	t_db_list	*tmp;

	if (lst)
	{
		if ((*lst)->next == NULL && (*lst)->prev == NULL)
			free((*lst));
		else if ((*lst)->next == NULL)
		{
			tmp = db_lstfirst((*lst));
			(*lst)->prev->next = NULL;
		}
		else if ((*lst)->prev == NULL)
		{
			tmp = (*lst)->next;
			(*lst)->next->prev = NULL;
		}
		else
		{
			tmp = db_lstfirst((*lst));
			(*lst)->next->prev = (*lst)->prev;
			(*lst)->prev->next = (*lst)->next;
		}
	}
	(void)tmp;
}
