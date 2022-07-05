/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:41:19 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 17:55:46 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_cmd_to_pipe(t_list *arg, int pipes)
{
	while (arg)
	{
		if (pipes == 0)
			return ;
		if (arg->type == CMD && pipes != 0 && arg->next->type != OUTPUT)
		{
			arg->type = C_T_P;
			pipes--;
		}
		arg = arg->next;
	}
}

void	init_check_cmd(int *pipes, int *count)
{
	*pipes = 0;
	*count = 0;
}

void	part_check_cmd(t_list **arg, int *pipes, int *count)
{
	(*arg)->type = SIGN;
	if ((*arg)->next
		&& ((*arg)->prev->type != OUTPUT))
		(*pipes)++;
	*count = 0;
}

void	check_cmd(t_list *arg)
{
	int		pipes;
	int		count;
	t_list	*head;
	char	*temp;

	head = arg;
	init_check_cmd(&pipes, &count);
	while (arg)
	{
		if ((arg->type == CMD || arg->type == ARG)
			&& ft_strcmp(arg->data, "|") != 0 && count == 0)
		{
			arg->type = CMD;
			temp = arg->data;
			arg->data = check_quotes(arg->data);
			free(temp);
			count++;
		}
		if (ft_strcmp(arg->data, "|") == 0)
			part_check_cmd(&arg, &pipes, &count);
		arg = arg->next;
	}
	arg = head;
	check_cmd_to_pipe(arg, pipes);
}

void	check_dollar(t_list	*arg)
{
	int		i;
	t_list	*head;
	t_list	*tmp;

	i = 0;
	head = arg;
	while (arg)
	{
		i = 0;
		if (arg->type != SIGN)
		{
			while (arg->data[i])
			{
				if (arg->data[i] == '$')
				{
					arg->dollar = 1;
					break ;
				}
				i++;
			}
		}
		arg = arg->next;
	}
}
