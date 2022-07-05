/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:42:08 by aabeid            #+#    #+#             */
/*   Updated: 2022/07/03 16:04:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	node_remover(t_export **head, t_export *del)
{
	if (!*head || !del)
		return ;
	if (*head == del)
		*head = del->next;
	if (del->next)
		del->next->prev = del->prev;
	if (del->prev)
		del->prev->next = del->next;
	free(del->var_val);
	free(del);
}

void	export_printer(t_export *list)
{
	t_export	*cmp;
	t_export	*save;
	t_export	*head;

	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
	{
		head = ft_lstmap(list);
		while (head)
		{
			cmp = head->next;
			save = head;
			while (cmp)
			{
				if (ft_astrcmp(save->var_val, cmp->var_val) > 0)
					save = cmp;
				cmp = cmp->next;
			}
			print(save->var_val);
			node_remover(&head, save);
		}
		ft_lstclear(&head);
		exit (0);
	}
}

int	checker(char *str, int param)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z')
			&& !(str[i] >= '0' && str[i] <= '9') && !(str[i] == '_')
			&& !(str[i] == '+' && str[i + 1] == '='))
		{
			if (param == 2)
				write (2, "bash: unset: `", 15);
			else
				write (2, "bash: export: `", 16);
			write (2, str, ft_strlen(str));
			write (2, "': not a valid identifier\n", 27);
			g_globe->pids[g_globe->pid_idx] = fork();
			if (g_globe->pids[g_globe->pid_idx++] == 0)
				exit (1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_var(char *str, int param)
{
	if ((str[0] >= '0' && str[0] <= '9')
		|| str[0] == '=')
	{
		if (param == 2)
			write (2, "bash: unset: `", 15);
		else
			write (2, "bash: export: `", 16);
		write (2, str, ft_strlen(str));
		write (2, "': not a valid identifier\n", 27);
		g_globe->pids[g_globe->pid_idx] = fork();
		if (g_globe->pids[g_globe->pid_idx++] == 0)
			exit (1);
		return (0);
	}
	if (0 == checker(str, param))
		return (0);
	g_globe->pids[g_globe->pid_idx] = fork();
	if (g_globe->pids[g_globe->pid_idx++] == 0)
		exit (0);
	return (1);
}

void	export(char **var_val, t_export **envs, t_list *token)
{
	int		token_idx;
	int		i;

	i = 0;
	if (!var_val || (token && token->type != ARG))
		export_printer(*envs);
	while (var_val && var_val[i])
	{
		if (check_var(var_val[i], 1) && check_existence(var_val[i],
				*envs, ft_strlen(var_val[i]) + 1) == 0)
		{
			token_idx = check_existence(var_val[i], *envs,
					get_var_len(var_val[i]));
			if (0 != token_idx && (var_val[i][get_var_len(var_val[i])]
				== '=' || var_val[i][get_var_len(var_val[i])] == '+'))
				replace_var(token_idx, var_val[i], envs);
			else
				ft_listadd_back(envs, ft_listnew(var_val[i]));
		}
		else
			free(var_val[i]);
		i++;
	}
	free(var_val);
}
