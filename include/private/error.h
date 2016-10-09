/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:43:27 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/04 16:09:21 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 96

typedef struct	s_error
{
	char		buffer[BUFF_SIZE];
	int			active;
}				t_error;

#endif
