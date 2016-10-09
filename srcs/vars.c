/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:08 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/08 18:59:29 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/vars.h"

static t_list	*g_variables;

int		get_var(const char *key, const char **out)
{
	t_list	*ptr;

	ptr = g_variables;
	while (ptr != NULL)
	{
		if (((t_entry*)ptr->content)->key == key)
			break ;
		ptr = ptr->next;
	}
	if (ptr == NULL)
	{
		*out = "";
		return (0);
	}
	*out = ((t_entry*)ptr->content)->value;
	return (0);
}

int		set_var(const char *key, const char *value)
{
	t_list	**ptr;
	t_entry	*new;
	t_list	*lst;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (set_error("memory allocation failed"));
	new->key = key;
	new->value = value;
	lst = ft_lstnew(new, sizeof(*new));
	if (lst == NULL)
		return (set_error("memory allocation failed"));
	ptr = &g_variables;
	while (*ptr != NULL && ((t_entry*)(*ptr)->content)->key != key)
		ptr = &(*ptr)->next;
	if (*ptr != NULL)
	{
		((t_entry*)(*ptr)->content)->value = value;
		free(new);
		return (0);
	}
	lst->next = *ptr;
	*ptr = lst;
	return (0);
}

int		delete_var(const char *key)
{
	t_list	**curr;
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	curr = &g_variables;
	while (*curr != NULL)
	{
		if (((t_entry*)(*curr)->content)->key == key)
			break ;
		prev = *curr;
		curr = &(*curr)->next;
	}
	if (curr == NULL)
		return (set_error("no such variable"));
	if (prev != NULL)
	{
		next = (*curr)->next;
		free(prev->next);
		prev->next = next;
		return (0);
	}
	free(*curr);
	*curr = NULL;
	return (0);
}

void	free_vars(void)
{
	ft_lstdel(&g_variables, NULL);
}
