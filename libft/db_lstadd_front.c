/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:54:09 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/01 12:23:08 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	db_lstadd_front(t_db_list **lst, t_db_list *new)
{
	if (*lst)
	{
		(*lst)->prev = new;
		new->next = *lst;
		new->prev = NULL;
	}
	*lst = new;
}
