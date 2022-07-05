/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gear.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:08:49 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	default_standards(int stds[2])
{
	dup2(stds[1], STDOUT_FILENO);
	dup2(stds[0], STDIN_FILENO);
	close(stds[1]);
	close(stds[0]);
}

void	status_getter(void)
{
	g_globe->pid_idx = 0;
	while (g_globe->pid_idx <= g_globe->tokens_num)
	{
		waitpid(g_globe->pids[g_globe->pid_idx], &g_globe->exit_status, 0);
		WIFEXITED(g_globe->exit_status);
		g_globe->pid_idx++;
	}
	g_globe->pid_idx = 0;
	if (g_globe->exit_status > 255)
		g_globe->exit_status /= 256;
}

void	multi_free(t_export *tokens)
{
	int	i;

	i = 0;
	while (tokens)
	{
		free(tokens);
		tokens = tokens->next;
	}
}

void	envs_init(t_export **envs, char **env)
{
	int	i;

	i = 0;
	*envs = NULL;
	while (env[i])
	{
		ft_listadd_back(envs, ft_listnew(ft_strdup(env[i++])));
	}
}
