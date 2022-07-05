/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:26:34 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/02 21:48:34 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	counter_word(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

void	return_space(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == -115)
				str[i][j] = ' ';
			j++;
		}
		i++;
	}
}

static int	counter_alpha(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*convert(char const *s, int j)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc((j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] && i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		k;
	char	**str;

	i = 0;
	k = 0;
	str = malloc((counter_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	check_spaces(s);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
			str[k++] = convert(s + i, counter_alpha(s + i, c));
		while (s[i] && s[i] != c)
			i++;
	}
	str[k] = 0;
	return_space(str);
	return (str);
}
