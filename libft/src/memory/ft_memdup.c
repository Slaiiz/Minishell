/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:14:10 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:05:40 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_memory.h"

void	*ft_memdup(const void *addr, size_t n)
{
	void	*new;

	if (n == 0 || ((new = malloc(n)) == NULL))
		return (NULL);
	return (ft_memcpy(new, addr, n));
}
