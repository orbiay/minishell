/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:02:30 by aabeid            #+#    #+#             */
/*   Updated: 2022/06/28 19:46:24 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_export	*ft_listnew(char *val)
{
	t_export	*p;

	p = malloc(sizeof (t_export));
	if (p == NULL)
		return (NULL);
	p -> var_val = val;
	p -> next = NULL;
	p -> prev = NULL;
	return (p);
}
