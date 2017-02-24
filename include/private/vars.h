/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:16 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/14 14:16:34 by vchesnea         ###   ########.fr       */
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
}						t_entry;

#endif
