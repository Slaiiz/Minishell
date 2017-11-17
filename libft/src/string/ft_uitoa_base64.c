/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:28:38 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:28:14 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

#include "libft_integer.h"
#include "libft_memory.h"

char	*ft_uitoa_base64(unsigned long n, int base)
{
	char			digits[64];
	unsigned int	index;
	unsigned int	count;
	char			*out;

	base = ft_min(ft_max(base, 2), 16);
	count = 0;
	while (1)
	{
		digits[count++] = "0123456789abcdef"[n % base];
		if ((n = n / base) == 0)
			break ;
	}
	if ((out = ft_memalloc(count + 1)) == NULL)
		return (NULL);
	index = 0;
	while (count--)
		*(out + index++) = digits[count];
	return (out);
}
