/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:04:10 by orbiay            #+#    #+#             */
/*   Updated: 2022/05/15 17:17:27 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;
	t_list	*save;

	if (!lst)
		return ;
	if (*lst)
	{
		temp = *lst;
		save = ft_lstlast(*lst);
		save -> next = new;
		new -> prev = save;
		return ;
	}
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != 0)
		lst = lst -> next;
	return (lst);
}

t_list	*lstnew(char *data)
{
	t_list	*new;

	new = malloc (sizeof(t_list));
	if (new == NULL)
		return(NULL);
	new -> data = data;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}