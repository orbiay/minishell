/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:54:33 by orbiay            #+#    #+#             */
/*   Updated: 2022/07/03 16:16:10 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*reader(char *input, t_export **envs)
{
	input = readline("\e[0;32mMinishell$ \e[0m");
	if (input == 0)
		return (NULL);
	if (ft_strcmp(input, "") != 0)
		add_history(input);
	func_join(&input);
	return (input);
}

void	read_add(char **env)
{
	t_export	*envs;
	char		*input;
	t_list		*argumets;
	char		**sp_input;

	envs_init(&envs, env);
	init_g_var();
	while (1)
	{
		input = reader(input, &envs);
		if (input == NULL)
			break ;
		sp_input = ft_split(input, ' ');
		argumets = create_and_add(sp_input);
		g_globe->tokens_num = lstsize(argumets);
		g_globe->pids = malloc(sizeof(int) * g_globe->tokens_num);
		if (error_pipe(sp_input) && error(sp_input) == 0
			&& multiple_red1(sp_input) && multiple_red2(sp_input)
			&& closed_q(input) == 0)
			enter_if(&argumets, &envs);
		ft_free2(sp_input);
		func_free(&input, &argumets);
	}
	free(g_globe);
	ft_lstclear(&envs);
}

int	main(int ac, char **av, char **env)
{
	signal(SIGINT, &handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	read_add(env);
}
