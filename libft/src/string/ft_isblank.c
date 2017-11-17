/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:31:37 by vchesnea          #+#    #+#             */
/*   Updated: 2015/12/09 16:52:34 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

int	ft_isblank(int c)
{
	int	valid[2];

	if ((unsigned int)c > 63)
		return (0);
	valid[0] = 0x00003E00;
	valid[1] = 0x00000001;
	return ((valid[c >> 5] >> (c & 31)) & 1);
}
