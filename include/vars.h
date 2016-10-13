/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:12 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/08 18:59:55 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

typedef struct s_entry	t_entry;

/*
** Structure of an environment variable.
*/

typedef struct			s_entry
{
	char const			*key;
	char const			*value;
	t_entry				*next;
}						t_entry;

/*
** Puts the value of environment variable named *key into address **out.
** In the event the key does not exists, an empty string is returned.
**  Returns 0 on success or NONZERO on failure. On failure an error is set.
*/

int						get_var(char const *key, char const **out);

/*
** Sets the environment variable named *key with the argument *value.
**  Returns 0 on success or NONZERO on failure. On failure an error is set.
*/

int						set_var(char const *key, char const *value);

/*
** Deletes the environment variable named *key.
**  Returns 0 on success or NONZERO on failure. On failure an error is set.
*/

int						delete_var(char const *key);

/*
** Returns a pointer to the environment variable list.
** Direct modification on it is not advised.
** For that purpose, use the set_var function.
*/

const t_entry			*get_vars(void);

/*
** Frees the entire environment variable list and its contents.
** Use free_vars whenever you finish execution.
*/

void					free_vars(void);

#endif
