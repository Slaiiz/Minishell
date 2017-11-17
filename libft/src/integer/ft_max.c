/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:32:32 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:42:04 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_integer.h"

int	ft_max(int a, int b)
{
	int	c;

	c = (a - b) >> 31;
	return ((a & ~c) + (b & c));
}
