/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:22:09 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/14 13:03:06 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_array.h"

void	ft_arrdel(void ***array, size_t len, void (*f)(void*))
{
	void	**tmp;

	tmp = *array;
	while (len)
	{
		if (f == NULL)
			free(*tmp++);
		else
			f(*tmp++);
		--len;
	}
	free(*array);
	*array = NULL;
}
