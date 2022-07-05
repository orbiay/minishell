/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:35:35 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 13:01:31 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	part5_create_and_add(char *sp_input, int *type, t_list **arg)
{
	t_list	*new;

	new = lstnew(sp_input, *type, 0, if_quote(sp_input, *type));
	ft_lstadd_back(arg, new);
	*type = ARG;
	return (2);
}

void	init_var(int *j, t_list **arg, int *type)
{
		*j = 0;
		*type = ARG;
		*arg = NULL;
}

void	init_var2(int *j, char *save, int *i)
{
	*j = 0;
	*save = 0;
	*i = 0;
}

void	init_var3(int *i, int *j, int *counter)
{
	*counter = 0;
	*j = 0;
	*i = -1;
}

void	func(t_list	*arg)
{
	while (arg)
	{
		if (ft_strcmp(arg->data, "|") == 0 && (arg->prev->type == HEREDOC
				|| arg->prev->type == APPEND
				|| arg->prev->type == OUTPUT || arg->prev->type == INPUT))
		{
			arg->prev->write_in = 1;
		}
		arg = arg->next;
	}
}
