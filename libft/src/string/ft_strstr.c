/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:48:30 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 13:29:42 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*pos;
	const char	*bak;
	char		c;

	bak = s2;
	pos = s1;
	if (*s2 == '\0')
		return ((char*)s1);
	while ((c = *s1++) != '\0')
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
			s1 = pos + 1;
			s2 = bak;
			pos = s1;
		}
	}
	return (NULL);
}
