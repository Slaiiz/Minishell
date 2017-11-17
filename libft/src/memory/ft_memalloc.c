/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:17:01 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:04:38 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_memory.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	void	*tmp;

	if ((ptr = malloc(size)) == NULL)
		return (NULL);
	tmp = ptr;
	while (size--)
		*((unsigned char*)ptr++) = '\0';
	return (tmp);
}
