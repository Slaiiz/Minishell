/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:28:38 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:27:52 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

#include "libft_integer.h"
#include "libft_memory.h"

char	*ft_uitoa_base(unsigned int n, int base)
{
	char			digits[32];
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
	if ((out = ft_memalloc(count + 2)) == NULL)
		return (NULL);
	index = 0;
	while (count--)
		*(out + index++) = digits[count];
	return (out);
}