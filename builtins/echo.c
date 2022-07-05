/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:26:06 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
/*
	HANDLE THIS: echo some test without quotes
*/

int	option_check(char **str, int j, int i, int *n)
{
	i = 0;
	*n = 1;
	while (str[i] && str[i][0] == '-')
	{
		j = 1;
		while (str[i][j] == 'n')
			j++;
		if (!str[i][j])
		{
			*n = 0;
			i++;
		}
		else
			break ;
	}
	return (i);
}

void	echo(char **str)
{
	int		i;
	int		j;
	int		n;
	char	*prt;

	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
	{
		i = option_check(str, i, j, &n);
		while (str[i])
		{
			prt = ft_strtrim(str[i], " ");
			write (1, prt, ft_strlen(prt));
			free(prt);
			i++;
			if (str[i])
				write (1, " ", 1);
		}
		if (n == 1)
			write (1, "\n", 1);
		exit (0);
	}
	ft_free2(str);
}
