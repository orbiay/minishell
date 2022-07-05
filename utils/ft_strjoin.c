/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:00:58 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/02 17:00:12 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	params_free(const char *s1, const char *s2, int fr)
{
	if (fr == 1 || fr == 3)
		free((char *)s1);
	if (fr == 2 || fr == 3)
		free((char *)s2);
}

char	*ft_astrjoin(char const *s1, char const *s2, int fr)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i;

	i = -1;
	if (s1 == NULL || s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (str == NULL)
		return (NULL);
	while (++i < s1_len)
		str[i] = s1[i];
	s1_len = 0;
	while (s1_len < s2_len)
	{
		str[i] = s2[s1_len];
		i++;
		s1_len++;
	}
	str[i] = '\0';
	params_free(s1, s2, fr);
	return (str);
}
