/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:12 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/27 17:08:58 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

/*
** Structure of an environment variable.
*/

typedef struct			s_entry
{
	char const			*key;
	char const			*value;
	struct s_entry		*next;
}						t_entry;

/*
** Puts the value of environment variable named *key into address **out.
** In the event the key does not exist, an empty string is returned.
**  Returns 0 on success or NON-ZERO on failure. On failure an error is set.
*/

int						get_var(char const *key, char const **out);

/*
** Sets the environment variable named *key with the argument *value.
**  Returns 0 on success or NON-ZERO on failure. On failure an error is set.
*/

int						set_var(char const *key, char const *value);

/*
** Deletes the environment variable named *key.
**  Returns 0 on success or NON-ZERO on failure. On failure an error is set.
*/

int						delete_var(char const *key);

/*
** Returns a pointer to the environment variable list.
** Direct modification on it is not advised.
** For that purpose, use the set_var function.
*/

const struct s_entry	*get_vars(void);

/*
** Frees the entire environment variable list and its contents.
** Use free_vars whenever you finish execution.
*/

void					free_vars(void);

#endif
