/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:30:11 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/01 19:44:37 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s2)
		return (-1);
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) +1) * sizeof(char));
	if (s1)
	{
		while (s1[i])
		{
			str[i] = ((char *)s1)[i];
			i++;
		}
	}
	lens1 = 0;
	while (s2[lens1])
	{
		str[i] = ((char *)s2)[lens1];
		i++;
		lens1++;
	}
	str[i] = '\0';
	return (str);
}

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	size_sub_str;

	i = 0;
	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	size_sub_str = min(ft_strlen(s) - start, len);
	str = malloc((size_sub_str + 1));
	if (str == 0)
		return (NULL);
	while (i < size_sub_str)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
