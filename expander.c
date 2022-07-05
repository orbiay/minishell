/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:11:22 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_rep(int p_one, char *token, char *envs)
{
	char	*last;
	char	*ret;
	int		p_two;

	p_two = p_one;
	if (envs)
	{
		while (token[p_two] == *envs++)
			p_two++;
		if (token[p_two++] == '?')
			envs--;
		last = ft_astrjoin(ft_substr(token, 0, p_one - 1), envs, 1);
		ret = ft_astrjoin(last, &token[p_two], 0);
		free(last);
	}
	else
	{
		while (token[++p_two] && token[p_two] != '$'
			&& token[p_two] != ' ');
		ret = ft_astrjoin(ft_substr(token, 0, p_one - 1), &token[p_two], 1);
	}
	free(token);
	return (ret);
}

char	*dol_rep_prt1(int p_one, char *tokens)
{
	char	*ret;
	char	*ex_val;

	ex_val = ft_itoa(g_globe->exit_status);
	ret = get_rep(p_one, tokens, ex_val);
	free(ex_val);
	return (ret);
}

char	*dol_rep(char *tokens, t_export *envs, char *var1, char *var2)
{
	int		p_one;

	while (envs)
	{
		p_one = 0;
		while (tokens[p_one++] != '$')
			;
		if (tokens[p_one] == '?')
			return (dol_rep_prt1(p_one, tokens));
		var1 = ft_substr(envs->var_val, 0, get_var_len(envs->var_val));
		var2 = ft_substr(&tokens[p_one], 0, get_var_len(&tokens[p_one]));
		if (ft_strchr(envs->var_val, '=')
			&& ft_strncmp(var1, var2, ft_strlen(envs->var_val)))
		{
			free(var1);
			free(var2);
			tokens = get_rep(p_one, tokens, envs->var_val);
			return (tokens);
		}
		free(var1);
		free(var2);
		envs = envs->next;
	}
	tokens = get_rep(p_one, tokens, NULL);
	return (tokens);
}

t_list	*expander(t_list *tokens, t_export *envs)
{
	t_list	*tmp;
	char	*var1;
	char	*var2;

	tmp = tokens;
	while (tmp)
	{
		while (ft_strchr(tmp->data, '$') && tmp->type != HEREDOC
			&& tmp->quote != 39)
			tmp->data = dol_rep(tmp->data, envs, var1, var2);
		tmp = tmp -> next;
	}
	return (tokens);
}
