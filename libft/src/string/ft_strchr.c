/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:19:43 by vchesnea          #+#    #+#             */
/*   Updated: 2015/12/02 18:26:56 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

char	*ft_strchr(const char *s, int c)
{
	char	tmp;

	while ((tmp = *s) != (char)c)
	{
		if (tmp == '\0')
			return ((char*)NULL);
		s++;
	}
	return ((char*)s);
}
