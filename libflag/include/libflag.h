/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libflag.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:11:10 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/11 16:49:02 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFLAG_H
# define LIBFLAG_H

# define FLAG_ERROR_OK        0
# define FLAG_ERROR_NOMATCH   1
# define FLAG_ERROR_MALLOC    2
# define FLAG_ERROR_BADSYNTAX 4

/*
** Forward declarations
*/

typedef struct s_flaglist	t_flaglist;

typedef enum				e_flagtype
{
	FLAG_TYPE_NONE,
	FLAG_TYPE_SWITCH,
	FLAG_TYPE_VALUE,
	FLAG_TYPE_HOOK
}							t_flagtype;

/*
** Appends a new flag definition to an existing flag list.
**  Returns FLAG_ERROR_OK on success, or any other value on failure.
*/

int							flag_add(t_flaglist **out, const char *flag,
							t_flagtype type, void *data);

/*
** Frees a given list of flags generated previously
** by libflag, zeroing its pointer before returning.
*/

void						flag_free(t_flaglist **list);

/*
** Parses the standard argument table given a list of flags.
**  Returns FLAG_ERROR_OK on success, or any other value on failure.
*/

int							flag_parse(t_flaglist *list, int argc, char **argv);

#endif
