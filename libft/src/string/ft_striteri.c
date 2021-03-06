/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:12:29 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/23 15:53:20 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*tmp;

	tmp = s;
	while (*s != '\0')
	{
		f((unsigned int)(s - tmp), s);
		s++;
	}
}
