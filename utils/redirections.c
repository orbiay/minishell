/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:52:12 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	appender(char *file)
{
	int		id;
	char	*str;

	file = quotes_off(file);
	if (!access(file, F_OK) && access(file, W_OK) == -1)
	{
		no_permission(file);
		free(file);
		return (-2);
	}
	id = open(file, O_WRONLY | O_APPEND | O_CREAT, 0600);
	free(file);
	dup2(id, STDOUT_FILENO);
	close(id);
	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
		exit (0);
	return (1);
}

int	output_red(char *output)
{
	int	id;

	output = quotes_off(output);
	if (output[0] == '\0')
	{
		input_not_found(output);
		return (-8);
	}
	if (!access(output, F_OK) && access(output, W_OK) == -1)
	{
		no_permission(output);
		free(output);
		return (-2);
	}
	id = open(output, O_TRUNC | O_WRONLY | O_CREAT, 0600);
	free(output);
	dup2(id, STDOUT_FILENO);
	close(id);
	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
		exit (0);
	return (1);
}

int	input_red(char *input)
{
	int	id;

	input = quotes_off(input);
	if (access(input, F_OK) == -1)
	{
		input_not_found(input);
		free(input);
		return (-8);
	}
	else if (access(input, R_OK) == -1)
	{
		no_permission(input);
		free(input);
		return (-8);
	}
	id = open(input, O_RDONLY);
	free(input);
	dup2(id, STDIN_FILENO);
	close(id);
	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
		exit (0);
	return (1);
}

int	redirections(t_list *tmp, t_export **envs)
{
	if (tmp->type == INPUT)
		return (input_red(ft_strdup(tmp->data)));
	else if (tmp->type == OUTPUT)
		return (output_red(ft_strdup(tmp->data)));
	else if (tmp->type == APPEND)
		return (appender(ft_strdup(tmp->data)));
	return (3);
}
