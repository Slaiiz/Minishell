/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:18:11 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/30 17:16:12 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft.h"

int	ft_bufsub(t_buff *buf, void *out, size_t size)
{
	if (buf->len < size)
		size = buf->len;
	ft_memcpy(out, buf->data, size);
	buf->len = buf->len - size;
	ft_memcpy(buf->data, buf->data + size, buf->len);
	return (size);
}
