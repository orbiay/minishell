/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:20 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	closed_q(char	*str)
{
	int		i;
	int		count;
	char	save;

	save = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (save == 0 && (str[i] == 34 || str[i] == 39))
			save = str[i];
		else if (str[i] == save)
			save = 0;
		i++;
	}
	if (save)
	{
		g_globe->exit_status = 258;
		printf("Error :Unclosed Quote %c :\n", save);
	}
	return (save);
}

int	part1_multiple_red2(int j)
{
	if (j == 3)
	{
		g_globe->exit_status = 258;
		printf("Minishell: syntax error near unexpected token `newline'\n");
		return (0);
	}
	if (j == 4)
	{
		g_globe->exit_status = 258;
		printf("Minishell: syntax error near unexpected token `<'\n");
		return (0);
	}
	if (j == 5)
	{
		g_globe->exit_status = 258;
		printf("Minishell: syntax error near unexpected token `<<'\n");
		return (0);
	}
	if (j >= 6)
	{
		g_globe->exit_status = 258;
		printf("Minishell: syntax error near unexpected token `<<<'\n");
		return (0);
	}
	return (1);
}

int	multiple_red2(char **sp_input)
{
	int	i;
	int	j;

	i = 0;
	while (sp_input[i])
	{
		j = 0;
		if (sp_input[i][0] == '<')
		{
			while (sp_input[i][j] == '<' && sp_input[i][j])
				j++;
		}
		if (!part1_multiple_red2(j))
			return (0);
		i++;
	}
	return (1);
}

int	multiple_red1(char	**sp_input)
{
	int		i;
	int		j;

	i = -1;
	while (sp_input[++i])
	{
		j = 0;
		if (sp_input[i][j] == '<' || sp_input[i][0] == '>')
			while ((sp_input[i][j] == '<' || sp_input[i][j] == '>')
				&& sp_input[i][j])
				j++;
		if (j == 3)
		{
			g_globe->exit_status = 258;
			printf("Minishell: syntax error near unexpected token `>'\n");
			return (0);
		}
		if (j > 3)
		{
			g_globe->exit_status = 258;
			printf("Minishell: syntax error near unexpected token `>>'\n");
			return (0);
		}
	}
	return (1);
}
