/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:35:06 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/13 13:01:38 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_db_list	*db_lstnew(void *content)
{
	t_db_list	*lst;

	lst = malloc(1 * sizeof(t_db_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}
