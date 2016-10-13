/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libflag.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:11:10 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/08 18:22:34 by vchesnea         ###   ########.fr       */
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

int							libflag_add(t_flaglist **out, const char fast,
							const char *slow, t_flagtype type, void *data);

void						libflag_free(t_flaglist **list);

int							libflag_parse(t_flaglist *list, int argc,
							char **argv);

#endif
