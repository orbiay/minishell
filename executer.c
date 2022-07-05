/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:42:56 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 17:29:27 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*quotes_off(char *var)
{
	char	*ret;
	char	c;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (var[(ft_strlen(var) - 1)] == '\"' || var[(ft_strlen(var) - 1)] == '\'')
	{
		ret = malloc(sizeof(char) * (ft_strlen(var) - 1));
		if (!ret)
			return (NULL);
		c = var[(ft_strlen(var) - 1)];
		while (var[j])
		{
			if (var[j] != c)
				ret[i++] = var[j];
			j++;
		}
		ret[i] = 0;
		free(var);
		return (ret);
	}
	return (var);
}

char	**pre_quotes_off(char *cmd, char **cmds, t_list *tokens)
{
	int	i;

	i = 0;
	free(cmd);
	while (cmds[i])
	{
		if (tokens->quote == 2 || tokens->quote == 0
			|| (tokens->type == ARG && tokens->quote != 39
				&& tokens->quote != 34))
			cmds[i] = quotes_off(cmds[i]);
		i++;
	}
	return (cmds);
}

char	**cmd_joiner(t_list *tokens)
{
	char	*cmd;
	char	**cmds;
	int		j;

	j = 0;
	if (!tokens || (tokens->prev && tokens->prev->type == C_T_P
			&& tokens->type != ARG))
		return (NULL);
	cmd = ft_astrjoin(tokens->data, " ", 0);
	while (tokens->next)
	{
		if (tokens->next->type == OPTION || tokens->next->type == ARG)
		{
			cmd = ft_astrjoin(cmd, tokens->next->data, 1);
			cmd = ft_astrjoin(cmd, " ", 1);
		}
		else if (tokens->next->type == CMD || tokens->next->type == C_T_P)
			break ;
		tokens = tokens->next;
	}
	cmds = ft_split(cmd, ' ');
	cmds = pre_quotes_off(cmd, cmds, tokens);
	return (cmds);
}

void	executer(t_list *tokens, t_export *envs)
{
	char	*path;
	char	**cmds;
	char	**env_vars;

	cmds = cmd_joiner(tokens);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	if (access(cmds[0], X_OK) == 0)
		path = cmds[0];
	else
		path = paths_getter(envs, cmds);
	env_vars = ltoa(envs);
	execve(path, cmds, env_vars);
	free(env_vars);
	cmd_not_found(cmds, path);
	exit(127);
}
