/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:23:32 by aabeid            #+#    #+#             */
/*   Updated: 2022/06/28 19:26:06 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_export	*ft_lstmap(t_export *lst)
{
	t_export	*list;
	t_export	*head;

	if (lst == NULL)
		return (NULL);
	head = NULL;
	while (lst)
	{
		list = ft_listnew(ft_strdup(lst->var_val));
		ft_listadd_back(&head, list);
		lst = lst -> next;
	}
	return (head);
}
