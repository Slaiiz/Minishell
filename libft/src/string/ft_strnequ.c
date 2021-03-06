/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:19:30 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 13:26:39 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (1);
	while (n-- > 1 && *s1 != '\0' && *s1 == *s2)
	{
		if (n == 0)
			return (1);
		s1++;
		s2++;
	}
	return (!(*s1 - *s2));
}
