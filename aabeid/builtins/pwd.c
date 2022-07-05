/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:26:47 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	DON'T FORGET TO HANDLE THE OLDPWD
	AND UPDATE THE DEFAULT ONE
*/

char	*pwd(t_export *env, int wrt)
{
	char	*ret;

	ret = getcwd(NULL, 0);
	if (!ret)
		ret = expander(lstnew("$PWD", 0, 0, 0), env)->data;
	if (wrt == 1)
	{
		g_globe->pids[g_globe->pid_idx] = fork();
		if (g_globe->pids[g_globe->pid_idx++] == 0)
		{
			write(1, ret, ft_strlen(ret));
			write(1, "\n", 1);
			exit (0);
		}
		free(ret);
	}
	return (ret);
}

//! HANDLE THE ERROR IN CASE OF PWD + "SOME ARGUMENT"