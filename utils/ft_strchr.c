/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:11:17 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/02 16:07:03 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while ((char)str[i] != (char)c && str[i] != '\0')
		i++;
	if (c == '$' && (!ft_isalpha(str[i + 1]) && str[i + 1] != '?'))
		return (0);
	if ((char)str[i] == (char)c)
		return (i + 1);
	return (0);
}
