/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:27:07 by vchesnea          #+#    #+#             */
/*   Updated: 2015/11/26 17:25:42 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

int	ft_isdigit(int c)
{
	int	valid[2];

	valid[0] = 0x00000000;
	valid[1] = 0x03FF0000;
	if (c > 63)
		return (0);
	else
		return ((valid[c >> 5] >> (c & 31)) & 1);
}
