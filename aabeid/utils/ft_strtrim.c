/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:17:16 by aabeid            #+#    #+#             */
/*   Updated: 2022/06/21 16:48:09 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	len_checker(int len)
{
	if (len < 0)
		len = 0;
	return (len);
}

int	check_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	int				s1_l;
	char			*str;
	int				j;

	j = 0;
	i = 0;
	if (!s1)
		return (NULL);
	s1_l = ft_strlen(s1);
	while (check_set(s1[i], set))
		i++;
	while (check_set(s1[s1_l - 1], set) && (s1_l - 1) > 0)
		s1_l--;
	str = malloc(len_checker(s1_l - i) + 1);
	if (str == NULL)
		return (NULL);
	while (i < s1_l)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
