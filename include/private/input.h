/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:50:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/04 16:50:37 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define BUFF_SIZE 32

# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

# include "../error.h"

typedef struct	s_buff
{
	char		*data;
	ssize_t		size;
	ssize_t		len;
}				t_buff;

#endif
