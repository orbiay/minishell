/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_space_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:45:37 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/02 21:48:44 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_pipes(char	*str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

char	*join_pipe_space(char *str)
{
	int		i;
	int		j;
	char	*save;

	j = 0;
	i = 0;
	save = malloc (ft_strlen(str) + (count_pipes(str) * 2) + 1);
	if (!save)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '|' && str[i + 1] == '|')
		{
			save[j++] = str[i++];
			save[j++] = ' ';
			save[j++] = str[i++];
			save[j++] = ' ';
		}
		save[j++] = str[i++];
	}
	save[j] = 0;
	free(str);
	return (save);
}

void	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			i++;
			while (str[i] && str[i] != 34 && str[i] != 39)
			{
				if (str[i] == ' ')
					str[i] = -115;
				i++;
			}
		}
		i++;
	}
}
