/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:30:11 by orbiay            #+#    #+#             */
/*   Updated: 2022/04/17 17:15:41 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int ft_strcmp(const char *s1, const char *s2) 
{
   while (*s1 != '\0' && *s2 != '\0'  && *s1 == *s2) {
      s1++;
      s2++;
   }
   return *s1 - *s2;
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
	if (!str)
		return (NULL);
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*ts1;
	unsigned char		*ts2;

	i = 0;
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	while ((ts1[i] || ts2[i]) && i < n)
	{
		if (ts1[i] != ts2[i])
			return (ts1[i] - ts2[i]);
		i++;
	}
	return (0);
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
	//if (check_space(s))
	//{
	//	str = split_cmd(s, str);
	//	return (str);
	//}
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
	return (str);
}


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}