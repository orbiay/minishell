/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_getter_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:18:36 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/02 22:01:08 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*path_finder(char **paths, char *path, char *arg)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		paths[i] = ft_astrjoin(paths[i], "/", 0);
		path = ft_astrjoin(paths[i], arg, 0);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		free(paths[i]);
		i++;
	}
	return (0);
}

char	*paths_getter(t_export *envs, char **arg)
{
	char	*path;
	char	**paths;

	path = NULL;
	if (!arg)
		return (0);
	while (envs)
	{
		if (ft_strncmp(envs->var_val, "PATH", 4))
		{
			path = envs->var_val;
			break ;
		}
		envs = envs->next;
	}
	if (!path)
		return (NULL);
	paths = ft_split(path, ':');
	paths[0] = ft_substr(paths[0], 5, ft_strlen(path) - 5);
	path = path_finder(paths, path, arg[0]);
	return (path);
}
