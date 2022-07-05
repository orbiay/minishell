/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:55:03 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	part_error_pipe(char *sp_input, char *sp_input1)
{
	if (ft_strcmp(sp_input, "||") == 0)
	{
		printf("Error : syntax error near unexpected token `||'\n");
		g_globe->exit_status = 258;
		return (0);
	}
	if (sp_input1 && ft_strcmp(sp_input, "|") == 0
		&& ft_strcmp(sp_input1, "|") == 0)
	{
		printf("Error :syntax error near unexpected token `|'\n");
		g_globe->exit_status = 258;
		return (0);
	}
	else if (ft_strcmp(sp_input, "|") == 0 && !sp_input1)
	{
		printf("Error :syntax error near unexpected token `|'\n");
		g_globe->exit_status = 258;
		return (0);
	}
	return (1);
}

int	part2_error_pipe(char *sp_input)
{
	if (!ft_strcmp(sp_input, "|"))
	{
		printf("Error : syntax error near unexpected token `|'\n");
		g_globe->exit_status = 258;
		return (0);
	}
	return (1);
}

void	init_var_pipe(int *i, int *j, int *save)
{
	*j = -1;
	*i = -1;
	*save = 1;
}

int	error_pipe(char **sp_input)
{
	int		i;
	int		j;
	int		save;

	init_var_pipe(&i, &j, &save);
	while (sp_input[++i])
	{
		save = part_error_pipe(sp_input[i], sp_input[i + 1]);
		if (save == 1)
			save = part2_error_pipe(sp_input[0]);
		if (save == 1 && sp_input[i][j] == '|' && sp_input[i][j + 1] == '|')
		{
			save = j + 1;
			while (sp_input[i][++j] && sp_input[i][j] == '|')
				j++;
			if (j > 0 && j > save)
				printf("Error : syntax error near unexpected token `||'\n");
			g_globe->exit_status = 258;
			return (0);
		}
		if (save == 0)
			return (0);
	}
	return (save);
}
