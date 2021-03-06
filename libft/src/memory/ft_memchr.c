/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:01:45 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:05:04 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
		if (*(unsigned char*)s++ == (unsigned char)c)
			return (void*)(s - 1);
	return (void*)NULL;
}
