/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:30:29 by orbiay            #+#    #+#             */
/*   Updated: 2022/04/17 18:21:30 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define INPUT 0
# define OUTPUT 1
# define HEREDOC 3
#define CMD 4
# define APPEND 5
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

typedef struct cmds
{
	char		*data;
	struct cmds	*next;
	int			type;
}t_list;

typedef struct args
{
	char		*data;
}t_args;

t_list	*lstnew(char *data);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_strlen(const char *str);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int ft_strcmp(const char *s1, const char *s2);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif