/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_apaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:48:17 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 13:02:35 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_space_2(char *str)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '<' || str[i] == '>')
			&& (str[i + 1] != '<' && str[i + 1] != '>'))
				counter++;
		i++;
	}
	return (counter);
}

void	part_join_space(int *j, int *counter)
{
	(*j)++;
	*counter = 0;
}

char	*join_space(char *str)
{
	int		i;
	int		j;
	int		counter;
	char	*save;

	init_var3(&i, &j, &counter);
	save = malloc (ft_strlen(str) + count_space_2(str) + 1);
	while (str[++i])
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
			part_join_space(&j, &counter);
		}
		save[i + j] = str[i];
	}
	save[i + j] = '\0';
	free(str);
	return (save);
}

int	count_space(char	*str)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] != '<' && str[i] != '>')
			&& (str[i + 1] == '<' || str[i + 1] == '>'))
				counter++;
		i++;
	}
	return (counter);
}

char	*join_space_ops(char *str)
{
	int			i;
	int			j;
	int			counter;
	char		*save;

	counter = 0;
	j = 0;
	i = 0;
	save = malloc (ft_strlen(str) + count_space(str) + 1);
	while (str[i])
	{
		if ((str[i] != '<' && str[i] != '>')
			&& (str[i + 1] == '<' || str[i + 1] == '>'))
		{
			save[j++] = str[i++];
			save[j++] = ' ';
			while ((str[i] == '<' || str[i] == '>') && str[i])
				save[j++] = str[i++];
		}
		save[j++] = str[i++];
	}
	save[j] = '\0';
	free(str);
	return (save);
}
