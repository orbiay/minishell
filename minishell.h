/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:30:29 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 16:11:48 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define INPUT			0
# define OUTPUT			1
# define HEREDOC		3
# define CMD			4
# define APPEND			5
# define OPTION			6
# define ARG			7
# define PIPE			8
# define SIGN			10
# define C_T_P			12
# define S_QUOTE		1
# define D_QUOTE		2

# include<stdio.h>
# include<stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <readline/readline.h>

typedef struct s_list
{
	struct s_list	*next;
	char			*data;
	int				type;
	int				dollar;
	int				quote;
	int				write_in;
	struct s_list	*prev;
}	t_list;

typedef struct s_export
{
	struct s_export	*prev;
	char			*var_val;
	struct s_export	*next;
}	t_export;

typedef struct s_globe
{
	int		p;
	int		dp;
	int		sig;
	int		im_in;
	int		*pids;
	int		enter;
	int		pid_idx;
	int		num_herdoc;
	int		tokens_num;
	int		exit_status;
	int		red_check[3];
}	t_globe;

t_globe	*g_globe;

char		*prompt(void);
char		*ft_itoa(int n);
void		init_g_var(void);
void		echo(char **str);
int			ft_isalpha(int c);
void		func(t_list *arg);
void		func(t_list	*arg);
void		status_getter(void);
int			closed_q(char *str);
void		env(t_export *envs);
void		sighandler(int sig);
void		print(char *var_val);
int			appender(char *file);
int			lstsize(t_list *lst);
void		type_arg(t_list *arg);
char		*ft_strdup(char *src);
void		my_exit(t_list *vars);
int			is_Quote(t_list *arg);
void		handle_sigint(int sig);
char		*remove_Q(char *input);
int			input_red(char *input);
t_export	*ft_listnew(char *val);
int			get_var_len(char *var);
char		*quotes_off(char *var);
char		**ltoa(t_export *envs);
void		check_cmd(t_list *arg);
int			error(char **sp_input);
char		*join_space(char *str);
void		check_spaces(char *str);
int			count_dollar(char *str);
t_list		*if_expand(char *input);
char		*check_quotes(char *str);
int			ft_atoi(const char *str);
void		func_join(char	**input);
int			output_red(char *output);
t_list		*ft_lstlast(t_list *lst);
void		read_add(char **env);
t_export	*ft_lstmap(t_export *lst);
char		*reader(char *input, t_export **envs);
void		ft_free2(char **sp_input);
void		no_permission(char *file);
void		ft_free2(char **sp_input);
void		check_dollar(t_list *arg);
char		*join_space_ops(char *str);
int			ft_strlen(const char *str);
int			ft_listsize(t_export *lst);
void		input_not_found(char *arg);
void		ft_free(t_list	*arguments);
int			error_pipe(char **sp_input);
char		**ft_split(char *s, char c);
t_export	*ft_listlast(t_export *lst);
char		*join_pipe_space(char *str);
void		ft_lstclear(t_export **lst);
void		multi_free(t_export *tokens);
void		multi_free(t_export *tokens);
char		**cmd_joiner(t_list *tokens);
int			if_quote(char *str, int type);
void		default_standards(int stds[2]);
int			multiple_red1(char **sp_input);
int			multiple_red2(char **sp_input);
int			ft_astrcmp(char *s1, char *s2);
void		export_printer(t_export *head);
char		*pwd(t_export *envs, int write);
char		*ft_strjoin(char *s1, char *s2);
int			check_var(char *str, int param);
t_list		*create_and_add(char **sp_input);
void		rl_replace_line(char *str, int i);
int			ft_strchr(const char *str, int c);
void		cd(t_list *token, t_export **envs);
void		cd_err(t_list *token, char *saved);
void		cmd_not_found(char **arg, char *path);
void		init_var2(int *j, char *save, int *i);
void		envs_init(t_export **envs, char **env);
void		envs_init(t_export **envs, char **env);
void		init_var3(int *i, int *j, int *counter);
void		executer(t_list *tokens, t_export *envs);
void		init_var(int *j, t_list **arg, int *type);
char		*paths_getter(t_export *envs, char **arg);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*expander(t_list *tokens, t_export *envs);
void		func_free(char **input, t_list **argumets);
void		minishell(t_list *tokens, t_export **envs);
int			redirections(t_list *tmp, t_export **envs);
void		unset(char **var_to_unset, t_export **envs);
void		enter_if(t_list **argumets, t_export **envs);
char		*ft_strtrim(char const *s1, char const *set);
void		stream_creator(t_export *envs, t_list *tokens);
void		ft_listadd_back(t_export **lst, t_export *new);
void		ft_listadd_front(t_export **lst, t_export *new);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_astrjoin(char const *s1, char const *s2, int fr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		replace_var(int idx, char *new_val, t_export **envs);
int			builtin(char *input, t_export **envs, t_list *tokens);
int			ft_strncmp2(const char *s1, const char *s2, size_t n);
void		export(char **var_val, t_export **envs, t_list *token);
t_list		*lstnew(char *data, int op, int dollar, int type_quote);
int			check_existence(char *cmd, t_export *envs, int cmd_len);
t_list		*lstnew1(char *data, int op, int dollar, int type_quote);
t_list		*lstnew_two(char *data, int op, int dollar, int type_quote);
int			heredoc_handler(char *delimiter, t_list *t, t_export *envs);
int			part5_create_and_add(char *sp_input, int *type, t_list **arg);

#endif