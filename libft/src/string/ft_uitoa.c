/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:28:38 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:28:23 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

#include "libft_memory.h"

char	*ft_uitoa(unsigned int n)
{
	char			digits[32];
	unsigned int	index;
	unsigned int	count;
	char			*out;

	count = 0;
	while (1)
	{
		digits[count++] = (char)(n % 10 + '0');
		if ((n = n / 10) == 0)
			break ;
	}
	if ((out = ft_memalloc(count + 1)) == NULL)
		return (NULL);
	index = 0;
	while (count--)
		*(out + index++) = digits[count];
	return (out);
}
