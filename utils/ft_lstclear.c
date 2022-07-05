/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:51:43 by aabeid            #+#    #+#             */
/*   Updated: 2022/06/29 17:41:45 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_lstclear(t_export **lst)
{
	t_export	*tmp;
	t_export	*current;

	current = *lst;
	while (current)
	{
		tmp = current -> next;
		free(current->var_val);
		free(current);
		current = tmp;
		tmp = NULL;
	}
	*lst = NULL;
}
