/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:00:27 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_num(char *str)
{
	while (*str != 0)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	my_exit(t_list *vars)
{
	t_list	*tmp;

	if (vars && vars->next)
	{
		write(2, "bash: exit: too many arguments\n", 31);
		return ;
	}
	else if (vars)
	{
		if (check_num(vars->data))
			exit (ft_atoi(vars->data));
		g_globe->pids[g_globe->pid_idx] = fork();
		if (g_globe->pids[g_globe->pid_idx++] == 0)
		{
			write(2, "bash: exit: ", 12);
			write(2, vars->data, ft_strlen(vars->data));
			write(2, ": numeric argument required\n", 28);
			exit (0);
		}
		exit (255);
	}
	exit (g_globe->exit_status);
}
