/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:38:03 by orbiay            #+#    #+#             */
/*   Updated: 2022/04/17 18:50:28 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"
// void type(char **sp_text)
// {
// 	if (ft_strcmp(sp_text[0],"<") == 0)
		
// }
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
		printf("%d\n",arguments->type);
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

void type_arg(t_list *arg)
{
	while (arg)
	{
		if (ft_strcmp(arg->data,"<") == 0)
		{
			arg->type = 10;
			arg = arg->next;
			arg->type = INPUT;
			arg = arg->next;
		}
		else if(ft_strcmp(arg->data,"|") == 0)
		{
			arg->type = 10;
			arg = arg->next;
			arg->type = CMD;
			arg = arg->next;
		}
		else if(ft_strcmp(arg->data,">") == 0)
		{
			arg->type = 10;
			arg = arg->next;
			arg->type = OUTPUT;
			arg = arg->next;
		}
		else if(ft_strcmp(arg->data,"<<") == 0)
		{
			arg->type = 10;
			arg = arg->next;
			arg->type = HEREDOC;
			arg = arg->next;
		}
		else if(ft_strcmp(arg->data,">>") == 0)
		{
			arg->type = 10;
			arg = arg->next;
			arg->type = APPEND;
			arg = arg->next;
		}
		else
		{
			arg->type = 10;
			arg->type = CMD;
			arg = arg->next;
		}
	}
}
void error(char **sp_input)
{
	int i = 0;
	while(sp_input[i])
	{
		//printf("##\n");
		if (ft_strcmp(sp_input[i],">" ) == 0 && ft_strcmp(sp_input[i+ 1],"") == 0)
		{
			printf("Minishell$ :syntax error near unexpected token `newline");
			exit(0);
		}
		else if (ft_strcmp(sp_input[i],">>") == 0 && ft_strcmp(sp_input[i+ 1],"") == 0)
		{
			printf("Minishell$ :syntax error near unexpected token `newline");
			exit(0);
		}
		else if (ft_strcmp(sp_input[i],"<" ) == 0&& ft_strcmp(sp_input[i+ 1],"") == 0)
		{
			printf("Minishell$ :syntax error near unexpected token `newline");
			exit(0);
		}
		else if (ft_strcmp(sp_input[i],"<<") == 0 && ft_strcmp(sp_input[i+ 1],"") == 0)
		{
			printf("Minishell$ :syntax error near unexpected token `newline");
			exit(0);
		}
		i++;
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
		sp_input = ft_split(input,' ');
		argumets = create_list(sp_input);
		error(sp_input);
		type_arg(argumets);
		affiche(argumets);
		input = readline("Minishell$ ");
	}
}
int main(int ac, char **av)
{
	read_add(av);
}