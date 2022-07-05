/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:19:05 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 18:14:06 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc_writer(t_list *t, char *ret, t_export *envs, int here_doc)
{
	t_list	*exp;

	if (t->quote == 0)
	{
		exp = expander(lstnew(ret, ARG, 1, 0), envs);
		write(here_doc, exp->data, ft_strlen(exp->data));
		write(here_doc, "\n", 1);
		free(ret);
		free(exp->data);
		free(exp);
	}
	else
	{
		write(here_doc, ret, ft_strlen(ret));
		write(here_doc, "\n", 1);
		free(ret);
	}
}

void	g_globe_set(int i)
{
	if (i == 1)
	{
		g_globe->im_in = 1;
		g_globe->enter = 0;
		g_globe->sig = 0;
	}
	else if (i == 2)
	{
		g_globe->enter = 0;
		g_globe->im_in = 0;
		g_globe->sig = 1;
	}
}

int	writer(char *delimiter, t_list *t, t_export *envs, int here_doc)
{
	char	*ret;

	while (1)
	{
		ret = readline("Heredoc: ");
		if (!ret && g_globe->enter)
		{
			g_globe->im_in = 0;
			free(delimiter);
			return (0);
		}
		if (!ret)
			ret = ft_strdup(delimiter);
		if (ft_strcmp(delimiter, ret) == 0)
			break ;
		heredoc_writer(t, ret, envs, here_doc);
	}
	free(ret);
	return (1);
}

int	heredoc_handler(char *delimiter, t_list *t, t_export *envs)
{
	int		here_doc[2];
	int		i;

	i = 0;
	g_globe_set(1);
	delimiter = quotes_off(delimiter);
	if (pipe(here_doc) == -1)
		write(2, "pipe_failure", 13);
	if (0 == writer(delimiter, t, envs, here_doc[1]))
		return (0);
	close(here_doc[1]);
	if (g_globe->num_herdoc - 1 == 0 && t->type == HEREDOC
		&& ((t->next && t->next->type != HEREDOC) || !t->next))
		dup2(here_doc[0], STDIN_FILENO);
	close(here_doc[0]);
	g_globe_set(2);
	g_globe->num_herdoc--;
	free(delimiter);
	return (1);
}
