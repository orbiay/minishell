/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:50:54 by orbiay            #+#    #+#             */
/*   Updated: 2022/05/19 15:02:26 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

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
			if (arg->prev->type != OPTION)
				arg->prev->type = CMD;//< file ls | ls > file
			if (arg->prev->type == OPTION)
				arg->prev->prev->type = CMD;//< file ls -l | ls > file
			if  (arg->next !=NULL)
			{
				arg = arg->next;
				arg->type = CMD;
			}
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
			arg->type = D_QUOTE;
		}
		else if(arg->data[0] == 39)
		{
			arg->type = S_QUOTE;
		}
		//else if(arg->data[0] == '$')
		//{
		//	arg->type = DOLLAR_SIGN;
		//}
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
	//arg = head;
	//int j = 0;
	//while (arg)
	//{
	//	j = 0;
	//		while(arg->data[j])
	//		{
	//			if (arg->data[j] == '$' && (arg->type != S_QUOTE &&arg->type != D_QUOTE) )
	//			{
	//				arg->type = DOLLAR_SIGN;
	//				break;
	//			}
	//			j++;
	//		}
	//	if(arg->data[0] == 34 && arg->data[1] == '$')
	//	{
	//		arg->type = D_QUOTE_DOLLAR;
	//	}
	//	else if(arg->data[0] == 39 && arg->data[1] == '$')
	//	{
	//		arg->type = S_QUOTE_DOLLAR;
	//	}
	//	arg = arg->next;
	//}
}

void check_dollar(t_list *arg)
{
	int i = 0;
	while (arg)
	{
		i = 0;
		if (arg->type != SIGN)
			while (arg->data[i])
			{
				if (arg->data[i] == '$')
				{
					arg->dollar = 1;
					break;
				}
				i++;
			}
		arg = arg->next;
	}
}