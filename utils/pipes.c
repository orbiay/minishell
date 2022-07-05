/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:24:01 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	stream_creator(t_export *envs, t_list *tokens)
{
	int		fd[2];

	if (pipe(fd) == -1)
		write(2, "pipe_failure\n", 13);
	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		executer(tokens, envs);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}
