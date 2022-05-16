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

void type_arg(t_list *arg)
{
	int i = 0;
	t_list *head;
	head = arg;
	while (arg)
	{
		if (ft_strcmp(arg->data,"<") == 0)
		{
			arg->type = SIGN;
			arg = arg->next;
			arg->type = INPUT;
		}
		else if(ft_strcmp(arg->data,"|") == 0)
		{
			arg->type = PIPE;
			arg = arg->next;
			arg->type = CMD;
		}
		else if(ft_strcmp(arg->data,">") == 0)
		{
			arg->type = SIGN;
			arg = arg->next;
			arg->type = OUTPUT;
		}
		else if(ft_strcmp(arg->data,"<<") == 0)
		{
			arg->type = SIGN;
			arg = arg->next;
			arg->type = HEREDOC;
		}
		else if(ft_strcmp(arg->data,">>") == 0)
		{
			arg->type = SIGN;
			arg = arg->next;
			arg->type = APPEND;
		}
		else if(arg->data[0] == '-')
		{
			arg->type = OPTION;
		}
		else if(arg->data[0] == 34)
		{
			printf("ssss\n");
			arg->type = D_QUOTE;
		}
		else if(arg->data[0] == 39)
		{
			arg->type = S_QUOTE;
		}
		else if(arg->data[0] == '$')
		{
			arg->type = DOLLAR_SIGN;
		}
		else if (i > 0)
		{
			arg->type = SIGN;
			arg->type = ARG;
		}
		else
			 arg->type = CMD;
		arg = arg->next;
		i++;
	}
	arg = head;
	int j = 0;
	while (arg)
	{
		j = 0;
			while(arg->data[j])
			{
				if (arg->data[j] == '$' && (arg->type != S_QUOTE &&arg->type != D_QUOTE) )
				{
					arg->type = DOLLAR_SIGN;
					break;
				}
				j++;
			}
		if(arg->data[0] == 34 && arg->data[1] == '$')
		{
			arg->type = D_QUOTE_DOLLAR;
		}
		else if(arg->data[0] == 39 && arg->data[1] == '$')
		{
			arg->type = S_QUOTE_DOLLAR;
		}
		arg = arg->next;
	}
}
int error(char **sp_input)
{
	int i = 0;
	int counter = 0;
	while(sp_input[i])
	{
		if (ft_strcmp(sp_input[i],">" ) == 0 && !sp_input[i+ 1])
		{
			printf("Minishell :syntax error near unexpected token `newline'\n");
			counter++;
			return (counter);
		}
		else if (ft_strcmp(sp_input[i],">>") == 0 && !sp_input[i+ 1])
		{
			printf("Minishell :syntax error near unexpected token `newline'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<" ) == 0&& !sp_input[i+ 1])
		{
			printf("Minishell :syntax error near unexpected token `newline'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<<") == 0 && !sp_input[i+ 1])
		{
			printf("Minishell :syntax error near unexpected token `newline'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<<") == 0 && ft_strcmp(sp_input[i + 1],">") == 0)
		{
			printf("Minishell :syntax error near unexpected token `>'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<") == 0 && ft_strcmp(sp_input[i + 1],">>") == 0)
		{
			printf("Minishell :syntax error near unexpected token `>'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<<") == 0 && ft_strcmp(sp_input[i + 1],">") == 0)
		{
			printf("Minishell$ :syntax error near unexpected token `>'\n");
			counter++;
			return(counter);
		}
		else if (ft_strcmp(sp_input[i],"<>") == 0)
		{
			printf("Minishell$ :syntax error near unexpected token `newline'\n");
			counter++;
			return(counter);
		}
		i++;
	}
	return(counter);
}

int count_space_2(char *str)
{
	int i = 0;
	int counter = 0;
	while (str[i])
	{
		if ((str[i] == '<' || str[i] == '>') && (str[i + 1] != '<' && str[i + 1] != '>'))
			counter++;
		i++;
	}
	return(counter);
}
char *join_space(char *str)
{
	int i = 0;
	int j = 0;
	int counter = 0;
	char *save;
	save = malloc (ft_strlen(str) + count_space_2(str) + 1);
	while (str[i])
	{
		while ((str[i] == '<' || str[i] == '>') && str[i])
		{
			save[i + j] = str[i];
			counter++;
			i++;
		}
		if (counter != 0)
		{
			save[i + j] = ' ';
			j++;
			counter = 0;
		}
		save[i + j] = str[i];
		i++;
	}
	save[i + j] = '\0';
	return(save);
}
int count_space(char *str)
{
	int i = 0;
	int counter = 0;
	while (str[i])
	{
		if ((str[i] != '<' && str[i] != '>') && (str[i + 1] == '<' || str[i + 1] == '>'))
			counter++;
		i++;
	}
	return(counter);
}
char *join_space_ops(char *str)
{
	int i = 0;
	int j = 0;
	int counter = 0;
	char *save;

	save = malloc (ft_strlen(str) + count_space(str) + 1);
	while (str[i])
	{
		if ((str[i] != '<' && str[i] != '>') && (str[i + 1] == '<' || str[i + 1] == '>'))
		{
			save[j++] = str[i++];
			save[j++] = ' ';
			while ((str[i] == '<' || str[i] == '>') && str[i])
				save[j++] = str[i++];
		}
		save[j++] = str[i++];
	}
	save[j] = '\0';
	return(save);
}
int count_pipes(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (str[i] == '|')
			count++;
		i++;
	}
	return(count);
}
char *join_pipe_space(char *str)
{
	int i = 0;
	int j = 0;
	char *save;
	save = malloc (ft_strlen(str) + (count_pipes(str) * 2)+ 1);
	
	while (str[i])
	{
		if(str[i] != '|' && str[i+1] == '|')
		{
			save[j++] = str[i++];
			save[j++] = ' ';
			save[j++] = str[i++];
			save[j++] = ' ';
		}
		save[j++] = str[i++];
	}
	return(save);
}

int multiple_red(char **sp_input)
{
	int i = 0;
	int j = 0;
	while (sp_input[i])
	{
		j = 0;
		if (sp_input[i][0] == '<' || sp_input[i][0] == '>')
		{
			while ((sp_input[i][j] == '<' || sp_input[i][j] == '>') && sp_input[i][j])
				j++;
		}
		if (j == 3)
		{

			printf("Minishell: syntax error near unexpected token `>'\n");
			return(0);
		}
		if (j > 3)
		{
			printf("Minishell: syntax error near unexpected token `>>'\n");
			return(0);
		}
		i++;
	}
	return(1);
}
//void check_dollar(t_list *arg)
//{
//	while (arg)
//	{
//		if (arg->type == D_QUOTE)
//			while (arg->data[i])
//			{
//				if (arg->data[i] == '$')
//					arg->type = D_QUOTE_DOLLAR;
//				i++;
//			}
//		arg = arg->next;
//	}
//}
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
			affiche(argumets);
		}
		input = readline("Minishell$ ");
	}
}
int main(int ac, char **av)
{
	read_add(av);
}
