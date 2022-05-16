/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:20 by orbiay            #+#    #+#             */
/*   Updated: 2022/05/16 14:46:50 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int error(char **sp_input)
{
	int i = 0;
	int counter = 0;
	while(sp_input[i])
	{
		if (ft_strcmp(sp_input[i],">" ) == 0 && !sp_input[i+ 1])
		{
			printf("Minishell :syntax error near unexpected token `newline'\n");
			counter++;
			return (counter);
		}
		else if (ft_strcmp(sp_input[i],">>") == 0 && !sp_input[i+ 1])
		{
			printf("Minishell :syntax error near unexpected token `newline'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<" ) == 0&& !sp_input[i+ 1])
		{
			printf("Minishell :syntax error near unexpected token `newline'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<<") == 0 && !sp_input[i+ 1])
		{
			printf("Minishell :syntax error near unexpected token `newline'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<<") == 0 && ft_strcmp(sp_input[i + 1],">") == 0)
		{
			printf("Minishell :syntax error near unexpected token `>'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<") == 0 && ft_strcmp(sp_input[i + 1],">>") == 0)
		{
			printf("Minishell :syntax error near unexpected token `>'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<<") == 0 && ft_strcmp(sp_input[i + 1],">") == 0)
		{
			printf("Minishell$ :syntax error near unexpected token `>'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<>") == 0)
		{
			printf("Minishell$ :syntax error near unexpected token `newline'\n");
			counter++;
			return(counter);
		}
		i++;
	}
	return(counter);
}

int multiple_red(char **sp_input)
{
	int i = 0;
	int j = 0;
	while (sp_input[i])
	{
		j = 0;
		if (sp_input[i][0] == '<' || sp_input[i][0] == '>')
		{
			while ((sp_input[i][j] == '<' || sp_input[i][j] == '>') && sp_input[i][j])
				j++;
		}
		if (j == 3)
		{

			printf("Minishell: syntax error near unexpected token `>'\n");
			return(0);
		}
		if (j > 3)
		{
			printf("Minishell: syntax error near unexpected token `>>'\n");
			return(0);
		}
		i++;
	}
	return(1);
}