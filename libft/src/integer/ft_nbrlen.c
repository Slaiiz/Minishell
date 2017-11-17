/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:59:16 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:45:42 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_integer.h"

int	ft_nbrlen(size_t n, int base)
{
	int	len;

	base = ft_min(ft_max(base, 2), 16);
	len = 0;
	while (1)
	{
		len++;
		if ((n = n / base) == 0)
			break ;
	}
	return (len);
}
