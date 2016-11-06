/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:23:07 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 18:11:14 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_array.h"

void	ft_arriter(void **array, size_t len, void (*f)(void**))
{
	while (len--)
	{
		f(&array[0]);
		++array;
	}
}