/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_buffer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:49:54 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/11 17:12:15 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BUFFER_H
# define LIBFT_BUFFER_H

# include <stdlib.h>

typedef struct	s_buff
{
	void		*data;
	size_t		size;
	size_t		len;
}				t_buff;

int				ft_bufadd(t_buff *buf, const void *data, size_t size);

void			ft_bufdel(t_buff **buf);

void			*ft_bufdup(t_buff *buf, size_t len);

t_buff			*ft_bufnew(void);

size_t			ft_bufsub(t_buff *buf, void *out, size_t size);

#endif
