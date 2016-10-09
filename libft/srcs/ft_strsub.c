/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:04:26 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/01 18:16:14 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new;

	new = malloc(sizeof(*s) * (len + 1));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s + start, len);
	new[len] = '\0';
	return (new);
}
