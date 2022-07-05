/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:18:40 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	env(t_export *envs)
{
	char	*var;

	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
	{
		while (envs)
		{
			if (ft_strchr(envs->var_val, '='))
				printf("%s\n", envs->var_val);
			envs = envs->next;
		}
		exit (0);
	}
}
