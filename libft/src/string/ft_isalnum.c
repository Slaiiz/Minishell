/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:34:37 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:11:55 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

int	ft_isalnum(int c)
{
	long valid[4];

	valid[0] = 0x00000000;
	valid[1] = 0x03FF0000;
	valid[2] = 0x07FFFFFE;
	valid[3] = 0x07FFFFFE;
	if ((unsigned int)c > 127)
		return (0);
	else
		return (valid[c >> 5] >> (c & 31) & 1);
}
