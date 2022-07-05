/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:08:10 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:58 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	if_quote(char *str, int type)
{
	int	i;

	i = 0;
	if (type == HEREDOC || type == ARG)
	{
		while (str[i])
		{
			if (str[i] == 39)
				return (39);
			if (str[i] == 34)
				return (34);
			i++;
		}
	}
	return (0);
}

int	count_quotes(char *str)
{
	int		i;
	int		j;
	char	save;

	save = 0;
	j = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == 39 || str[i] == 34) && save == 0)
		{
			save = str[i];
			j++;
		}
		else if (save == str[i])
		{
			save = 0;
			j++;
		}
		i++;
	}
	return (j);
}

char	*check_quotes(char	*str)
{
	int		i;
	int		j;
	char	save;
	char	*data;

	init_var2(&j, &save, &i);
	data = malloc(ft_strlen(str) - count_quotes(str) + 1);
	while (str[i])
	{
		if ((str[i] == 39 || str[i] == 34) && save == 0)
		{
			save = str[i];
			i++;
		}
		else if (save == str[i])
			save = 0;
		else
		{
			data[j] = str[i];
			i++;
			j++;
		}
	}
	data[j] = '\0';
	return (data);
}

void	init_g_var(void)
{
	g_globe = malloc(sizeof(t_globe));
	g_globe->exit_status = 0;
	g_globe->im_in = 0;
	g_globe->dp = 0;
	g_globe->enter = 0;
	g_globe->sig = 1;
	g_globe->pid_idx = 0;
	g_globe->num_herdoc = 0;
}
