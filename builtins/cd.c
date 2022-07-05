/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:52:50 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:46:31 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <dirent.h>

void	exit_with_zero(void)
{
	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
		exit (0);
}

void	get_pwd(t_export **envs, char *get, int op)
{
	char	*to_splt;
	char	**splt;

	if (op == 1)
	{
		to_splt = ft_astrjoin("PWD=", get, 2);
		splt = ft_split(to_splt, ' ');
		export(splt, envs, NULL);
		free(to_splt);
	}
	else if (op == 2)
	{
		to_splt = ft_astrjoin("OLDPWD=", get, 2);
		splt = ft_split(to_splt, ' ');
		export(splt, envs, NULL);
		free(to_splt);
	}
}

void	env_updater(t_export **envs, char *saved, t_list *node)
{
	get_pwd(envs, saved, 2);
	get_pwd(envs, pwd(*envs, 0), 1);
	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
		exit (0);
	free(node->data);
	free(node);
}

int	access_dir(int err, t_list *token, t_list *node, char *saved)
{
	err = chdir(token->data);
	if (err == -1)
	{
		cd_err(token, saved);
		free(node->data);
		free(node);
		return (0);
	}
	return (1);
}

void	cd(t_list *token, t_export **envs)
{
	int		err;
	char	*oldpwd;
	t_list	*node;
	char	*saved;

	node = lstnew("$PWD", 0, 0, 0);
	saved = ft_strdup(expander(node, *envs)->data);
	if (token)
		if (0 == access_dir(err, token, node, saved))
			return ;
	if (!token)
	{
		free(node->data);
		free(node);
		node = lstnew("$HOME", 0, 0, 0);
		oldpwd = ft_strdup(expander(node, *envs)->data);
		err = chdir(oldpwd);
		free(oldpwd);
	}
	get_pwd(envs, saved, 2);
	get_pwd(envs, pwd(*envs, 0), 1);
	exit_with_zero();
	free(node->data);
	free(node);
}
