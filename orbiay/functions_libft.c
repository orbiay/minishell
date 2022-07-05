/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:04:10 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/02 19:50:17 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

t_list	*lstnew_two(char *data, int op, int dollar, int type_quote)
{
	t_list	*new;

	new = malloc (sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> data = ft_strdup(data);
	new -> type = op;
	new -> dollar = dollar;
	new -> quote = type_quote;
	new -> next = NULL;
	new -> prev = NULL;
	new -> write_in = 0;
	free(data);
	return (new);
}

t_list	*lstnew(char *data, int op, int dollar, int type_quote)
{
	t_list	*new;

	new = malloc (sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> data = ft_strdup(data);
	new -> type = op;
	new -> dollar = dollar;
	new -> quote = type_quote;
	new -> next = NULL;
	new -> prev = NULL;
	new -> write_in = 0;
	return (new);
}

int	lstsize(t_list *lst)
{
	int	i;

	if (lst == 0)
		return (0);
	i = 0;
	while (lst != '\0')
	{
		if (lst->type != ARG && lst->type != OPTION)
			i++;
		lst = lst -> next;
	}
	return (i);
}
