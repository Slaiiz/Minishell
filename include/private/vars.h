/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:16 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/30 13:50:24 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include <stdlib.h>
# include "libft.h"

/*
** Structure of an environment variable.
*/

typedef struct			s_entry
{
	char				*key;
	char				*value;
	struct s_entry		*next;
}						t_entry;

#endif
