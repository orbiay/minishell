/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:35:08 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 15:58:29 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ltoa(t_export *envs)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(ft_listsize(envs) * sizeof(char *));
	while (envs)
	{
		ret[i++] = envs->var_val;
		envs = (envs)->next;
	}
	ret[i] = NULL;
	return (ret);
}

void	ft_free(t_list	*arguments)
{
	t_list	*temp;

	while (arguments)
	{
		temp = arguments -> next;
		free(arguments->data);
		free(arguments);
		arguments = temp;
	}
}

int	calcul(char	*input, char c, int start)
{
	while (input[start])
	{
		if (input[start] == c)
			break ;
		start++;
	}
	return (start);
}

void	ft_free2(char **sp_input)
{
	int	i;

	i = 0;
	while (sp_input && sp_input[i])
	{
		free(sp_input[i]);
		i++;
	}
	if (sp_input)
		free(sp_input);
}
