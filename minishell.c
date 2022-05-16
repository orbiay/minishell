/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:38:03 by orbiay            #+#    #+#             */
/*   Updated: 2022/05/16 14:52:48 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

t_list *create_list(char **sp_input)
{
	int		i;
	t_list *new;
	t_list *arguments = NULL;
	i = 0;
	while (sp_input[i])
	{
		new = lstnew(sp_input[i]);
		ft_lstadd_back(&arguments, new);
		i++;
	}
	return(arguments);
}

void affiche(t_list *arguments)
{
	while (arguments)
	{
		if (arguments->type != 10)
		{
			if (arguments->type == INPUT)
				printf("[INPUT] %s\n",arguments->data);
			else if (arguments->type == OUTPUT)
				printf("[OUTPUT] %s\n",arguments->data);
			else if (arguments->type == HEREDOC)
				printf("[HERDOC] %s\n",arguments->data);
			else if (arguments->type == CMD)
				printf("[CMD] %s\n",arguments->data);
			else if (arguments->type == APPEND)
				printf("[APPEND] %s\n",arguments->data);
			else if (arguments->type == OPTION)
				printf("[OPTION] %s\n",arguments->data);
			else if (arguments->type == ARG)
				printf("[ARG] %s\n",arguments->data);
			else if (arguments->type == D_QUOTE)
				printf("[D_QUOTE] %s\n",arguments->data);
			else if (arguments->type == S_QUOTE)
				printf("[S_QUOTE] %s\n",arguments->data);
			else if (arguments->type == DOLLAR_SIGN)
				printf("[DOLLAR_SIGN] %s\n",arguments->data);
			else if (arguments->type == D_QUOTE_DOLLAR)
				printf("[D_QUOTE_DOLLAR] %s\n",arguments->data);
			else if (arguments->type == S_QUOTE_DOLLAR)
				printf("[S_QUOTE_DOLLAR] %s\n",arguments->data);
			
		}
		arguments = arguments->next;
	}
}
void ft_free(t_list *arguments)
{
	while (arguments)
	{
		free(arguments);
		arguments = arguments->next;
	}
}

void read_add(char **av)
{
	char *input;
	t_list *argumets;
	char **sp_input;

	input = readline("Minishell$ ");
	while (input)
	{
		add_history(input);
		input = join_space(input);
		input = join_space_ops(input);
		input = join_pipe_space(input);
		sp_input = ft_split(input,' ');
		argumets = create_list(sp_input);
		if (error(sp_input) == 0 && multiple_red(sp_input))
		{
			type_arg(argumets);
			check_dollar(argumets);
			affiche(argumets);
		}
		input = readline("Minishell$ ");
	}
}
int main(int ac, char **av)
{
	read_add(av);
}