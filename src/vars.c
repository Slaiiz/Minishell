/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:08 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/23 16:02:15 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/vars.h"

#include "error.h"

static t_entry	*g_variables;

/*
** Returns the value of environment variable named *key.
** In the event the key does not exist, an empty string is returned.
*/

const char		*get_var(const char *key)
{
	t_entry	*curr;

	curr = g_variables;
	while (curr != NULL)
	{
		if (ft_strequ(curr->key, key))
			break ;
		curr = curr->next;
	}
	if (curr == NULL)
		return ("");
	return (curr->value);
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
		if (ft_strequ((*curr)->key, key))
		{
			free((*curr)->value);
			(*curr)->value = ft_strdup(value);
			return (0);
		}
		curr = &(*curr)->next;
	}
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (set_error(ERR_NOMEMORY));
	new->next = g_variables;
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	if (new->key == NULL || new->value == NULL)
		return (set_error(ERR_NOMEMORY));
	g_variables = new;
	return (0);
}

/*
** Deletes the environment variable named *key.
**  Returns 0 on success or NONZERO on failure. On failure an error is set.
*/

int				delete_var(const char *key)
{
	t_entry	**curr;
	t_entry	**next;

	curr = &g_variables;
	while (*curr != NULL)
	{
		if (ft_strequ((*curr)->key, key))
			break ;
		curr = &(*curr)->next;
	}
	if (*curr == NULL)
		return (set_error(ERR_VARNOTFOUND, key));
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
