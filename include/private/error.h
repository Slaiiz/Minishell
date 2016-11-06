/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:43:27 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 17:44:17 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 96

typedef struct	s_error
{
	char		buffer[BUFF_SIZE];
	int			active;
}				t_error;

#endif
