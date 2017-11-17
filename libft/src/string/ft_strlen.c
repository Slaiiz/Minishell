/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:02:59 by vchesnea          #+#    #+#             */
/*   Updated: 2015/11/25 16:16:33 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

size_t	ft_strlen(const char *s)
{
	const char *tmp;

	tmp = s;
	while (*s != '\0')
		s++;
	return (s - tmp);
}
