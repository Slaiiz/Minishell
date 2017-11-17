/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:01:32 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:04:32 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_memory.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char*)s + n) = '\0';
}
