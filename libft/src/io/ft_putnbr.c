/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:22:06 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 14:56:18 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_io.h"

#include "libft_string.h"

void	ft_putnbr(int n)
{
	char	*str;

	str = ft_itoa(n);
	write(1, str, ft_strlen(str));
}
