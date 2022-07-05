/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:07:03 by aabeid            #+#    #+#             */
/*   Updated: 2022/05/25 19:00:20 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_export	*ft_listlast(t_export *lst)
{
	t_export	*current;

	if (lst == 0)
		return (0);
	current = lst;
	while (current -> next != 0)
		current = current -> next;
	return (current);
}
