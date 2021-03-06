/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:28:38 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:24:09 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

#include "libft_memory.h"

char	*ft_itoa(int n)
{
	char			digits[32];
	unsigned int	negative;
	unsigned int	index;
	unsigned int	count;
	char			*out;

	if (n == (int)0x80000000)
		return ("-2147483648");
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
