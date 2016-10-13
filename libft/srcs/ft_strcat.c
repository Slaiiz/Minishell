/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:25:52 by vchesnea          #+#    #+#             */
/*   Updated: 2015/11/25 16:10:24 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *tmp;

	tmp = s1;
	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
	return (tmp);
}
