/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:04:57 by aabeid            #+#    #+#             */
/*   Updated: 2021/11/15 20:18:50 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_len(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_putnum(long n, int len)
{
	char	*s;

	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
	{
		s[len] = n + '0';
	}
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		s[len] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*nums;
	long	nb;

	nb = n;
	len = check_len(nb);
	nums = ft_putnum(nb, len);
	return (nums);
}
