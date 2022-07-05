/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:58:31 by aabeid            #+#    #+#             */
/*   Updated: 2022/05/25 19:01:02 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_listsize(t_export *lst)
{
	int			i;
	t_export	*count;

	i = 0;
	count = lst;
	while (count != 0)
	{
		i++;
		count = count -> next;
	}
	return (i);
}
