/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:38:35 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:56:16 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

#include "libft_memory.h"

char	*ft_strtrim(const char *s)
{
	const char		*pos;
	unsigned int	len;

	while (ft_isblank(*s))
		s++;
	len = ft_strlen(s);
	pos = s + len - 1;
	while (pos >= s && ft_isblank(*pos))
		pos--;
	len = (unsigned int)(pos - s + 1);
	if ((pos = (const char*)malloc(len + 1)) == NULL)
		return (NULL);
	ft_memcpy((char*)pos, (char*)s, len);
	*((char*)pos + len) = '\0';
	return ((char*)pos);
}
