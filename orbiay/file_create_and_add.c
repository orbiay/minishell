/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_create_and_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:31:10 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	part1_create_and_add(char *sp_input, int *type)
{
	if (ft_strcmp(sp_input, "<") == 0)
	{
		*type = INPUT;
		return (2);
	}
	else if (ft_strcmp(sp_input, ">") == 0)
	{
		*type = OUTPUT;
		return (2);
	}
	else if (ft_strcmp(sp_input, "<<") == 0)
	{
		*type = HEREDOC;
		g_globe->num_herdoc++;
		return (2);
	}
	else if (ft_strcmp(sp_input, ">>") == 0)
	{
		*type = APPEND;
		return (2);
	}
	return (1);
}

int	part2_create_and_add(char *sp_input, int *type, t_list **arg)
{
	t_list	*new;

	if (ft_strcmp(sp_input, "|") == 0)
	{
		new = lstnew(sp_input, SIGN, 0, 0);
		ft_lstadd_back(arg, new);
		*type = CMD;
		return (2);
	}
	else if (count_dollar(sp_input) && sp_input[0] == 34
		&& (sp_input[ft_strlen(sp_input) - 1] == 34
			|| sp_input[ft_strlen(sp_input) - 1] == 39)
		&& *type != OUTPUT && *type != HEREDOC && *type != APPEND
		&& *type != INPUT && *type != CMD)
	{
		*type = ARG;
		ft_lstadd_back(arg, if_expand(sp_input));
		*type = ARG;
		return (2);
	}
	return (1);
}

int	part3_create_and_add(char *sp_input, int *type, t_list **arg)
{
	t_list	*new;

	if (count_dollar(sp_input) && (sp_input[0] == 39
			&& (sp_input[ft_strlen(sp_input) - 1] == 39
				|| sp_input[ft_strlen(sp_input) - 1] == 34)
			&& *type != OUTPUT && *type != HEREDOC && *type != APPEND
			&& *type != INPUT && *type != CMD))
	{
		*type = ARG;
		ft_lstadd_back(arg, if_expand(sp_input));
		*type = ARG;
		return (2);
	}
	else if (count_dollar(sp_input) == 0 && sp_input[0] == 34
		&& sp_input[ft_strlen(sp_input) - 1] == 34
		&& *type != OUTPUT && *type != HEREDOC && *type != APPEND
		&& *type != INPUT && *type != CMD)
	{
		*type = ARG;
		new = lstnew(sp_input, *type, 0, 2);
		ft_lstadd_back(arg, new);
		*type = ARG;
		return (2);
	}
	return (1);
}

int	part4_create_and_add(char *sp_input, int *type, t_list **arg)
{
	t_list	*new;

	if (count_dollar(sp_input) == 0 && sp_input[0] == 39
		&& sp_input[ft_strlen(sp_input) - 1] == 39
		&& *type != OUTPUT && *type != HEREDOC
		&& *type != APPEND && *type != INPUT && *type != CMD)
	{
		*type = ARG;
		new = lstnew(sp_input, *type, 0, 1);
		ft_lstadd_back(arg, new);
		*type = ARG;
		return (2);
	}
	else if (sp_input[0] == '-')
	{
		*type = OPTION;
		new = lstnew(sp_input, *type, 0, 0);
		ft_lstadd_back(arg, new);
		*type = ARG;
		return (2);
	}
	return (1);
}

t_list	*create_and_add(char **sp_input)
{
	int			type;
	t_list		*arg;
	int			count;
	int			j;

	init_var(&j, &arg, &type);
	while (sp_input[j])
	{
		count = 1;
		count = part1_create_and_add(sp_input[j], &type);
		if (count == 1)
		{
			count = part2_create_and_add(sp_input[j], &type, &arg);
			if (count == 1)
				count = part3_create_and_add(sp_input[j], &type, &arg);
			if (count == 1)
				count = part4_create_and_add(sp_input[j], &type, &arg);
		}
		if (count != 2)
			count = part5_create_and_add(sp_input[j], &type, &arg);
		j++;
	}
	return (arg);
}
