/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:08:39 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/02 20:57:58 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	mid_end(char *var_to_unset, t_export *tmp, int var_len)
{
	t_export	*head;

	while (tmp->next)
	{
		if (ft_strncmp(tmp->next->var_val, var_to_unset,
				var_len) == 1
			&& (tmp->next->var_val[var_len] == '='
				|| tmp->next->var_val[var_len] == '\0'))
		{
			head = tmp->next;
			if (head->next)
				head->next->prev = head->prev;
			if (head->prev)
				head->prev->next = head->next;
			free(head->var_val);
			free(head);
			return ;
		}
		tmp = tmp->next;
	}
}

void	unset(char **var_to_unset, t_export **envs)
{
	t_export	*tmp;
	int			var_len;
	int			i;

	i = -1;
	while (var_to_unset && var_to_unset[++i])
	{
		tmp = *envs;
		var_len = get_var_len(var_to_unset[i]);
		if (check_var(var_to_unset[i], 2) == 1)
		{
			if (ft_strncmp(tmp->var_val, var_to_unset[i], var_len) == 1
				&& tmp->var_val[var_len] == '=')
			{
				tmp = (*envs);
				(*envs) = (*envs)->next;
				(*envs)->prev = NULL;
				free(tmp->var_val);
				free(tmp);
				break ;
			}
			mid_end(var_to_unset[i], tmp, var_len);
		}
	}
	ft_free2(var_to_unset);
}
