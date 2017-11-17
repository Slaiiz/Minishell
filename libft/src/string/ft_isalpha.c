/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:21:20 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:12:02 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

int	ft_isalpha(int c)
{
	int	valid[4];

	valid[0] = 0x00000000;
	valid[1] = 0x00000000;
	valid[2] = 0x07FFFFFE;
	valid[3] = 0x07FFFFFE;
	if ((unsigned int)c > 127)
		return (0);
	else
		return ((valid[c >> 5] >> (c & 31)) & 1);
}
