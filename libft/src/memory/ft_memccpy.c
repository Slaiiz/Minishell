/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:01:56 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:04:58 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_memory.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	tmp;

	while (n--)
	{
		tmp = *((unsigned char*)src++);
		*((unsigned char*)dst++) = tmp;
		if (tmp == (unsigned char)c)
			return (dst);
	}
	return (void*)NULL;
}
