/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:43:59 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/02 16:04:47 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_listadd_back(t_export **lst, t_export *new)
{
	t_export	*tail;

	tail = *lst;
	while (tail)
	{
		if (!tail -> next)
		{
			tail -> next = new;
			new -> prev = tail;
			return ;
		}
		tail = tail -> next;
	}
	if (!lst)
		*lst = ft_listnew(NULL);
	*lst = new;
}
