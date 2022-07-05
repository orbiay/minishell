/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:22:00 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 16:13:24 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	part_of_error(char *sp_input, char *sp_input_1)
{
	int	counter;

	counter = 0;
	if (ft_strcmp(sp_input, ">" ) == 0 && !sp_input_1)
	{
		printf("Minishell :syntax error near unexpected token `newline'\n");
		counter++;
		return (counter);
	}
	else if (ft_strcmp(sp_input, ">>") == 0 && !sp_input_1)
	{
		printf("Minishell :syntax error near unexpected token `newline'\n");
		counter++;
		return (counter);
	}
	else if (ft_strcmp(sp_input, "<" ) == 0 && !sp_input_1)
	{
		printf("Minishell :syntax error near unexpected token `newline'\n");
		counter++;
		return (counter);
	}
	return (counter);
}

int	part2_of_error(char *sp_input, char *sp_input_1)
{
	int	counter;

	counter = 0;
	if (ft_strcmp(sp_input, "<<") == 0 && !sp_input_1)
	{
		g_globe->exit_status = 258;
		printf("Minishell :syntax error near unexpected token `newline'\n");
		counter++;
		return (counter);
	}
	else if (sp_input_1 && ft_strcmp(sp_input, "<<") == 0
		&& ft_strcmp(sp_input_1, ">") == 0)
	{
		printf("Minishell :syntax error near unexpected token `>'\n");
		counter++;
		return (counter);
	}
	else if (sp_input_1 && ft_strcmp(sp_input, "<") == 0
		&& ft_strcmp(sp_input_1, ">>") == 0)
	{
		printf("Minishell :syntax error near unexpected token `>'\n");
		counter++;
		return (counter);
	}
	return (counter);
}

int	part3_of_error(char *sp_input, char *sp_input_1)
{
	int	counter;

	counter = 0;
	if (sp_input_1 && ft_strcmp(sp_input, "<<") == 0
		&& ft_strcmp(sp_input_1, ">") == 0)
	{
		g_globe->exit_status = 258;
		printf("Minishell$ :syntax error near unexpected token `>'\n");
		counter++;
		return (counter);
	}
	else if ((sp_input_1 && ft_strcmp(sp_input, "<<>>") == 0)
		|| (sp_input_1 && !ft_strcmp(sp_input, "<<")
			&& !ft_strcmp(sp_input_1, "<<")))
	{
		g_globe->exit_status = 258;
		printf("Minishell$ :syntax error near unexpected token `>>'\n");
		counter++;
		return (counter);
	}
	return (counter);
}

int	part4_of_error(char *sp_input, char *sp_input_1)
{
	int	counter;

	counter = 0;
	if ((sp_input_1 && ft_strcmp(sp_input, ">><<") == 0)
		|| (sp_input_1 && !ft_strcmp(sp_input, "<<")
			&& !ft_strcmp(sp_input_1, "<<")))
	{
		g_globe->exit_status = 258;
		printf("Minishell$ :syntax error near unexpected token `<<'\n");
		counter++;
		return (counter);
	}
	else if (ft_strcmp(sp_input, "<>") == 0)
	{
		g_globe->exit_status = 258;
		printf("Minishell$ :syntax error near unexpected token `newline'\n");
		counter++;
		return (counter);
	}
	return (counter);
}

int	error(char	**sp_input)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (sp_input[i])
	{
		counter = part_of_error(sp_input[i], sp_input[i + 1]);
		if (counter == 0)
			counter = part2_of_error(sp_input[i], sp_input[i + 1]);
		if (counter == 0)
			counter = part3_of_error(sp_input[i], sp_input[i + 1]);
		if (counter == 0)
			counter = part4_of_error(sp_input[i], sp_input[i + 1]);
		i++;
	}
	return (counter);
}
