/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:20:42 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 14:55:02 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_io.h"

void	ft_putendl(const char *s)
{
	while (*s != '\0')
		write(1, s++, 1);
	write(1, "\n", 1);
	return ;
}