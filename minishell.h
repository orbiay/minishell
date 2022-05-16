/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:30:29 by orbiay            #+#    #+#             */
/*   Updated: 2022/05/16 15:08:26 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
#define SIGN 10
# define INPUT 0
# define OUTPUT 1
# define OPTION 6
# define HEREDOC 3
#define CMD 4
# define APPEND 5
#define ARG 7
#define PIPE 8
#define D_QUOTE 9
#define S_QUOTE 11
#define DOLLAR_SIGN 12
#define D_QUOTE_DOLLAR 13
#define S_QUOTE_DOLLAR 14
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

typedef struct cmds
{
	char		*data;
	struct cmds	*next;
	struct cmds *prev;
	int			type;
}t_list;

int error(char **sp_input);
int multiple_red(char **sp_input);
t_list	*lstnew(char *data);
char *join_space(char *str);
void check_dollar(t_list *arg);
void type_arg(t_list *arg);
char *join_space_ops(char *str);
char *join_pipe_space(char *str);
t_list	*ft_lstlast(t_list *lst);
int	ft_strlen(char *str);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int ft_strcmp(const char *s1, const char *s2);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
