/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:11:26 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 13:11:44 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	part1_if_expand(char *input, int *i, t_list **new)
{
	int		start;
	char	save;

	start = 0;
	save = input[*i];
	(*i)++;
	start = *i;
	while (input[*i])
	{
		if (input[*i] == save)
			break ;
		(*i)++;
	}
	ft_lstadd_back(new, lstnew_two
		(ft_substr(input, start, *i - start), ARG, 0, save));
	(*i)++;
	return (0);
}

int	part2_if_expand(char *input, int *i, t_list **new)
{
	int		start;
	char	save;

	start = *i;
	save = 0;
	while (input[*i] && input[*i] != 39 && input[*i] != 34)
		(*i)++;
	if (ft_strcmp(ft_substr(input, start, *i - start), "") != 0)
		ft_lstadd_back(new, lstnew_two
			(ft_substr(input, start, *i - start), ARG, 0, save));
	return (0);
}

t_list	*if_expand(char *input)
{
	int			i;
	t_list		*new;

	new = NULL;
	i = 0;
	while (input[i])
	{
		if (input[i] == 34 || input[i] == 39)
			part1_if_expand(input, &i, &new);
		else
			part2_if_expand(input, &i, &new);
	}
	return (new);
}
