/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:16 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 17:44:35 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include <stdlib.h>
# include "libft/libft.h"

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
