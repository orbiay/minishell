/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_apaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:48:17 by orbiay            #+#    #+#             */
/*   Updated: 2022/05/16 14:49:13 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int count_space_2(char *str)
{
	int i = 0;
	int counter = 0;
	while (str[i])
	{
		if ((str[i] == '<' || str[i] == '>') && (str[i + 1] != '<' && str[i + 1] != '>'))
			counter++;
		i++;
	}
	return(counter);
}
char *join_space(char *str)
{
	int i = 0;
	int j = 0;
	int counter = 0;
	char *save;
	save = malloc (ft_strlen(str) + count_space_2(str) + 1);
	while (str[i])
	{
		while ((str[i] == '<' || str[i] == '>') && str[i])
		{
			save[i + j] = str[i];
			counter++;
			i++;
		}
		if (counter != 0)
		{
			save[i + j] = ' ';
			j++;
			counter = 0;
		}
		save[i + j] = str[i];
		i++;
	}
	save[i + j] = '\0';
	return(save);
}
int count_space(char *str)
{
	int i = 0;
	int counter = 0;
	while (str[i])
	{
		if ((str[i] != '<' && str[i] != '>') && (str[i + 1] == '<' || str[i + 1] == '>'))
			counter++;
		i++;
	}
	return(counter);
}
char *join_space_ops(char *str)
{
	int i = 0;
	int j = 0;
	int counter = 0;
	char *save;

	save = malloc (ft_strlen(str) + count_space(str) + 1);
	while (str[i])
	{
		if ((str[i] != '<' && str[i] != '>') && (str[i + 1] == '<' || str[i + 1] == '>'))
		{
			save[j++] = str[i++];
			save[j++] = ' ';
			while ((str[i] == '<' || str[i] == '>') && str[i])
				save[j++] = str[i++];
		}
		save[j++] = str[i++];
	}
	save[j] = '\0';
	return(save);
}
int count_pipes(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (str[i] == '|')
			count++;
		i++;
	}
	return(count);
}
char *join_pipe_space(char *str)
{
	int i = 0;
	int j = 0;
	char *save;
	save = malloc (ft_strlen(str) + (count_pipes(str) * 2)+ 1);
	
	while (str[i])
	{
		if(str[i] != '|' && str[i+1] == '|')
		{
			save[j++] = str[i++];
			save[j++] = ' ';
			save[j++] = str[i++];
			save[j++] = ' ';
		}
		save[j++] = str[i++];
	}
	return(save);
}