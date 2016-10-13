/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:16 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/08 18:58:17 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include <stdlib.h>
# include "libft.h"

# include "../error.h"

typedef struct s_entry	t_entry;

/*
** Structure of an environment variable.
*/

typedef struct			s_entry
{
	char				*key;
	char				*value;
	t_entry				*next;
}						t_entry;

#endif
