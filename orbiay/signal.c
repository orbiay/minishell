/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:07:42 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		if (g_globe->im_in == 0)
		{
			if (g_globe->sig)
				printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			g_globe->exit_status = 1;
		}
		if (g_globe->im_in == 1)
		{
			g_globe->dp = dup(0);
			close(0);
			g_globe->exit_status = 1;
			g_globe->enter = 1;
		}
	}
	if (sig == SIGQUIT)
	{
		g_globe->exit_status = 131;
		exit(131);
	}
}
