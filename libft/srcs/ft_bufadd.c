/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:30:43 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/30 17:16:10 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft.h"

int	ft_bufadd(t_buff *buf, const void *data, size_t size)
{
	void	*new;

	if ((buf->size - buf->len) < size)
	{
		buf->size += buf->size / 2;
		if (buf->size - buf->len < size)
			buf->size = buf->len + size;
		new = malloc(sizeof(*new) * buf->size);
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
