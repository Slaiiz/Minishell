/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:35:03 by vchesnea          #+#    #+#             */
/*   Updated: 2015/11/25 16:33:42 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp;

	tmp = s1;
	while (*s1 != '\0')
		s1++;
	while (n-- && *s2 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
	return (tmp);
}
