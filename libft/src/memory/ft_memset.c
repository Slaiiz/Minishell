/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:00:02 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:06:08 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_memory.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*((unsigned char*)b + len) = (unsigned char)c;
	return (b);
}
