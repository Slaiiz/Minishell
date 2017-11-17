/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:02:33 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:05:49 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_memory.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		direction;
	void	*tmp;

	tmp = dst;
	if (dst > src)
	{
		direction = -1;
		dst += len - 1;
		src += len - 1;
	}
	else
		direction = 1;
	while (len--)
	{
		*((unsigned char*)dst) = *((unsigned char*)src);
		dst += direction;
		src += direction;
	}
	return (tmp);
}
