/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot13.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:20:56 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:10:48 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_special.h"

#include "libft_string.h"

char	*ft_rot13(char *s)
{
	char	*tmp;

	tmp = s--;
	while (*++s != '\0')
		if (ft_isalpha(*s))
			*s = "NOPQRSTUVWXYZABCDEFGHIJKLM"[(*s & ~32) - 'A'] | (*s & 32);
	return (tmp);
}
