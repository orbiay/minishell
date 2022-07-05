/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:08:18 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execution_2(t_list *t, t_export **envs, int std_in)
{
	if (t && t->type != SIGN)
	{
		if (t->type != C_T_P && t->type != HEREDOC
			&& builtin(t->data, envs, t));
		else if (t->type == CMD)
		{
			g_globe->pids[g_globe->pid_idx] = fork();
			if (g_globe->pids[g_globe->pid_idx++] == 0)
				executer(t, *envs);
		}
		else if (t->type == C_T_P)
			stream_creator(*envs, t);
	}
	if (t && t->type == SIGN)
	{
		status_getter();
		dup2(std_in, STDOUT_FILENO);
		close (std_in);
		std_in = dup(1);
	}
	return (std_in);
}

int	execution_1(t_list **t, t_export **envs)
{
	int		ret;
	t_list	*tmp;

	ret = 0;
	tmp = *t;
	while (tmp && tmp->type != SIGN)
	{
		ret = redirections(tmp, envs);
		if (ret == -8 || ret == -1)
			break ;
		tmp = tmp->next;
	}
	if (ret == -8)
		while ((*t) && (*t)->type != SIGN)
			(*t) = (*t)->next;
	return (ret);
}

int	builtin(char *input, t_export **envs, t_list *tokens)
{
	if (tokens->type == CMD)
	{
		if (!ft_strcmp(input, "export"))
			export(cmd_joiner(tokens->next), envs, tokens->next);
		else if (!ft_strcmp(input, "env")
			&& (!tokens -> next || tokens->next->type != ARG))
			env(*envs);
		else if (!ft_strcmp(input, "pwd"))
			pwd(*envs, 1);
		else if (tokens->next && !ft_strcmp(input, "unset"))
			unset(cmd_joiner(tokens->next), envs);
		else if (!ft_strcmp(input, "cd"))
			cd(tokens->next, envs);
		else if (tokens->next && !ft_strcmp(input, "echo"))
			echo(cmd_joiner(tokens->next));
		else if (!ft_strcmp(input, "exit"))
			my_exit(tokens->next);
		else
			return (0);
	}
	return (1);
}

void	heredoc(t_list *tmp, t_export *envs)
{
	while (tmp)
	{
		if (tmp->type == HEREDOC && !g_globe->enter)
			heredoc_handler(ft_strdup(tmp->data), tmp, envs);
		tmp = tmp->next;
	}
}

void	minishell(t_list *t, t_export **envs)
{
	t_list		*tmp;
	int			stds[2];
	int			ret;

	ret = 0;
	signal(SIGINT, SIG_IGN);
	stds[1] = dup(1);
	stds[0] = dup(0);
	t = expander(t, *envs);
	g_globe->enter = 0;
	tmp = t;
	heredoc(tmp, *envs);
	while (t)
	{
		ret = execution_1(&t, envs);
		if (ret != -8)
		{
			execution_2(t, envs, stds[1]);
			t = t->next;
		}
	}
	status_getter();
	default_standards(stds);
	signal(SIGINT, &handle_sigint);
}
