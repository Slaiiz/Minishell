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

static t_entry	*g_variables;

/*
** Puts the value of environment variable named *key into address **out.
** In the event the key does not exists, an empty string is returned.
**  Returns 0 on success or NONZERO on failure. On failure an error is set.
*/

int				get_var(char const *key, char const **out)
{
	t_entry	*ptr;

	ptr = g_variables;
	while (ptr != NULL)
	{
		if (!ft_strcmp(ptr->key, key))
			break ;
		ptr = ptr->next;
	}
	if (ptr == NULL)
	{
		*out = "";
		return (-1);
	}
	*out = ptr->value;
	return (0);
}

/*
** Sets the environment variable named *key with the argument *value.
**  Returns 0 on success or NONZERO on failure. On failure an error is set.
*/

int				set_var(char *key, char *value)
{
	t_entry	*ptr;
	t_entry	*new;

	ptr = g_variables;
	while (ptr != NULL)
	{
		if (!ft_strcmp(ptr->key, key))
		{
			free(ptr->value);
			ptr->value = value;
			return (0);
		}
		ptr = ptr->next;
	}
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (set_error("memory allocation failed"));
	new->key = key;
	new->value = value;
	new->next = g_variables;
	g_variables = new;
	return (0);
}

/*
** Deletes the environment variable named *key.
**  Returns 0 on success or NONZERO on failure. On failure an error is set.
*/

int				delete_var(char const *key)
{
	t_entry	**prev;
	t_entry	**curr;

	prev = NULL;
	curr = &g_variables;
	while (*curr != NULL)
	{
		if (!ft_strcmp((*curr)->key, key))
			break ;
		prev = curr;
		curr = &(*curr)->next;
	}
	if (*curr == NULL)
		return (set_error("no such variable"));
	free((*curr)->value);
	free((*curr)->key);
	if (*prev != NULL)
		(*prev)->next = (*curr)->next;
	free(*curr);
	if (*prev == NULL)
		*curr = NULL;
	return (0);
}

/*
** Returns a pointer to the environment variable list.
** Direct modification on it is not advised.
** For that purpose, use the set_var function.
*/

const t_entry	*get_vars(void)
{
	return (g_variables);
}

/*
** Frees the entire environment variable list and its contents.
** Use free_vars whenever you finish execution.
*/

void			free_vars(void)
{
	t_entry	*curr;
	t_entry	*next;

	curr = g_variables;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->key);
		free(curr->value);
		free(curr);
		curr = next;
	}
	g_variables = NULL;
}
