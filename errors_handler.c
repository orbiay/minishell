/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:54:40 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	input_not_found(char *input)
{
	write(2, "bash: ", 7);
	write(2, input, ft_strlen(input));
	write(2, ": No such file or directory\n", 28);
	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
		exit (1);
}

void	no_permission(char *str)
{
	write(2, "bash: ", 7);
	write(2, str, ft_strlen(str));
	write(2, ": Permission denied\n", 20);
	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
		exit (1);
}

void	cmd_not_found(char **arg, char *path)
{
	if (ft_strchr(arg[0], '/'))
	{
		write(2, "bash: ", 7);
		write(2, arg[0], ft_strlen(arg[0]));
		write(2, ": No such file or directory\n", 28);
	}
	else
	{
		write(2, "bash: ", 7);
		write(2, arg[0], ft_strlen(arg[0]));
		write(2, ": command not found\n", 20);
	}
}

void	cd_err(t_list *token, char *saved)
{
	write (2, "bash: cd: ", 11);
	write (2, token->data, ft_strlen(token->data));
	write (2, ": No such file or directory\n", 28);
	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
		exit (1);
	free(saved);
}
