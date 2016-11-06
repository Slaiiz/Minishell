/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:30:43 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:38:45 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_buffer.h"

#include "libft_memory.h"

int	ft_bufadd(t_buff *buf, const void *data, size_t size)
{
	void	*new;

	if (buf->size < (size + buf->len))
	{
		buf->size += buf->size / 2;
		if (buf->size < size + buf->len)
			buf->size = size + buf->len;
		new = malloc(buf->size);
		if (new == NULL)
			return (-1);
		if (buf->data != NULL)
		{
			ft_memcpy(new, buf->data, buf->len);
			free(buf->data);
		}
		buf->data = new;
	}
	ft_memcpy(buf->data + buf->len, data, size);
	buf->len += size;
	return (0);
}
