/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:18:11 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/31 15:29:54 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft.h"

ssize_t	ft_bufsub(t_buff *buf, void *out, ssize_t size)
{
	ssize_t	shrink;
	void	*new;

	if (size > buf->len)
		size = buf->len;
	if (size > 0)
	{
		ft_memcpy(out, buf->data, size);
		buf->len = buf->len - size;
		shrink = 2 * buf->size / 3;
		if (buf->len <= shrink)
		{
			new = malloc(shrink);
			if (new == NULL)
				return (-1);
			ft_memcpy(new, buf->data + size, buf->len);
			buf->size = shrink;
			free(buf->data);
			buf->data = new;
			return (size);
		}
		ft_memcpy(buf->data, buf->data + size, buf->len);
	}
	return (size);
}
