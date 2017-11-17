/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:01:47 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:05:14 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_memory.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *tmp;

	tmp = dst;
	while (n--)
		*((unsigned char*)tmp++) = *((unsigned char*)src++);
	return (dst);
}
