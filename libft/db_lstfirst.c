/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:59:42 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/01 12:23:04 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_db_list	*db_lstfirst(t_db_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev != NULL)
	{
		lst = lst->prev;
	}
	return (lst);
}
