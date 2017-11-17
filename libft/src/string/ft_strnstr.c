/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:48:30 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 13:27:16 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*pos;
	const char	*bak;
	char		c;

	bak = s2;
	if ((pos = s1) && *s2 == '\0')
		return ((char*)s1);
	while (n-- && (c = *s1++) != '\0')
	{
		if (c == *s2)
		{
			if (s2++ == bak)
				pos = s1 - 1;
			if (*s2 == '\0')
				return ((char*)pos);
		}
		else
		{
			n += (size_t)(s1 - pos - 1);
			s1 = pos + 1;
			s2 = bak;
			pos = s1;
		}
	}
	return (NULL);
}
