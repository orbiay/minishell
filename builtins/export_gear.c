/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_gear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:26:20 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 15:26:23 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_existence(char *cmd, t_export *envs, int cmd_len)
{
	int		token_idx;

	token_idx = 1;
	while (envs && !ft_strncmp(envs->var_val, cmd, cmd_len))
	{
		token_idx++;
		envs = envs->next;
	}
	if (envs)
		return (token_idx);
	return (0);
}

void	replace_var(int idx, char *new_val, t_export **envs)
{
	t_export	*tmp;
	int			i;

	i = 0;
	tmp = *envs;
	while (tmp && idx != ++i)
		tmp = tmp->next;
	i = 0;
	if (tmp)
	{
		if (!ft_strchr(tmp->var_val, '='))
			tmp->var_val = ft_astrjoin(tmp->var_val, "=", 1);
		while (new_val[i] != '=')
			i++;
		if (new_val[i] == '=' && new_val[i - 1] == '+')
		{
			tmp->var_val = ft_astrjoin(tmp->var_val, &new_val[++i], 1);
			free(new_val);
		}
		else
		{
			free(tmp->var_val);
			tmp->var_val = new_val;
		}
	}
}

void	print(char *var_val)
{
	int	i;

	i = 0;
	write(1, "declare -x ", 11);
	while (var_val[i] && var_val[i - 1] != '=')
		write(1, &var_val[i++], 1);
	if (var_val[i - 1] == '=')
	{
		write(1, "\"", 1);
		while (var_val[i] && var_val[i] != '\0')
			write(1, &var_val[i++], 1);
		write(1, "\"", 1);
	}
	write(1, "\n", 1);
}
