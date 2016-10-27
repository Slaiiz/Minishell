/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:08 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/27 17:06:13 by vchesnea         ###   ########.fr       */
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
	t_entry	*curr;

	curr = g_variables;
	while (curr != NULL)
	{
		if (!ft_strcmp(curr->key, key))
			break ;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		*out = "";
		return (-1);
	}
	*out = curr->value;
	return (0);
}

/*
** Sets the environment variable named *key with the argument *value.
**  Returns 0 on success or NONZERO on failure. On failure an error is set.
*/

int				set_var(char *key, char *value)
{
	t_entry	*new;
	t_entry	**curr;

	curr = &g_variables;
	while (*curr != NULL)
	{
		if (!ft_strcmp((*curr)->key, key))
		{
			free((*curr)->value);
			(*curr)->value = ft_strdup(value);
			return (0);
		}
		curr = &(*curr)->next;
	}
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (set_error("memory allocation failed"));
	new->next = g_variables;
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	if (new->key == NULL || new->value == NULL)
		return (set_error("memory allocation failed"));
	g_variables = new;
	return (0);
}

/*
** Deletes the environment variable named *key.
**  Returns 0 on success or NONZERO on failure. On failure an error is set.
*/

int				delete_var(char const *key)
{
	t_entry	**curr;
	t_entry	**next;

	curr = &g_variables;
	while (*curr != NULL)
	{
		if (!ft_strcmp((*curr)->key, key))
			break ;
		curr = &(*curr)->next;
	}
	if (*curr == NULL)
		return (set_error("no such variable"));
	next = &(*curr)->next;
	free((*curr)->value);
	free((*curr)->key);
	free(*curr);
	*curr = *next;
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
