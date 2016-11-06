/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libflag.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:16:45 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 18:21:41 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFLAG_H
# define LIBFLAG_H

# include <stdlib.h>
# include "libft/libft.h"

# define FLAG_ERROR_OK        0
# define FLAG_ERROR_NOMATCH   1
# define FLAG_ERROR_MALLOC    2
# define FLAG_ERROR_BADSYNTAX 4

/*
** Forward declarations
*/

typedef enum				e_flagtype
{
	FLAG_TYPE_NONE,
	FLAG_TYPE_SWITCH,
	FLAG_TYPE_VALUE,
	FLAG_TYPE_HOOK
}							t_flagtype;

typedef struct				s_flaglist
{
	char					fast;
	const char				*slow;
	enum e_flagtype			type;
	void					*data;
	struct s_flaglist		*next;
}							t_flaglist;

#endif
