/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:28:38 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:24:41 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

#include "libft_memory.h"

char	*ft_itoa64(long n)
{
	char			digits[64];
	unsigned int	negative;
	unsigned int	index;
	unsigned int	count;
	char			*out;

	if (n == (long)0x8000000000000000)
		return (ft_strdup("-9223372036854775808"));
	if ((negative = n < 0))
		n = -n;
	count = 0;
	while (1)
	{
		digits[count++] = (char)(n % 10 + '0');
		if ((n = n / 10) == 0)
			break ;
	}
	index = negative && 1;
	if ((out = ft_memalloc(count + index + 1)) == NULL)
		return (NULL);
	if (negative)
		*out = '-';
	while (count--)
		*(out + index++) = digits[count];
	return (out);
}
