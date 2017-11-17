/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:24:44 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 13:24:33 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	const char	*tmp;
	void		*buf;

	tmp = s;
	while (*s != '\0')
		s++;
	if ((buf = malloc((unsigned int)(s - tmp + 1))) == NULL)
		return (NULL);
	s = tmp;
	tmp = buf;
	while (*s != '\0')
		*((char*)buf++) = f(*s++);
	*((char*)buf) = '\0';
	return ((char*)tmp);
}
