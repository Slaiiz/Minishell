/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/09 17:30:21 by vchesnea          #+#    #+#             */
/*   Updated: 2016/00/09 17:30:21 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

char	*ft_strupcase(char *s)
{
	char	*tmp;

	tmp = s;
	while (*s != '\0')
	{
		if (ft_isalpha(*s))
			*s &= -33;
		s++;
	}
	return (tmp);
}
