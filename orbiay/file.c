/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:06:52 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 16:08:39 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	func_join(char	**input)
{
	*input = join_space(*input);
	*input = join_space_ops(*input);
	*input = join_pipe_space(*input);
}

void	enter_if(t_list **argumets, t_export **envs)
{
	check_cmd(*argumets);
	check_dollar(*argumets);
	func(*argumets);
	minishell(*argumets, envs);
}

void	func_free(char **input, t_list **argumets)
{
	free(g_globe->pids);
	free(*input);
	ft_free(*argumets);
}
