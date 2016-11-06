/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:22:09 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 18:18:51 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_array.h"

void	ft_arrdel(void ***array, size_t len, void (*f)(void**))
{
	void	**tmp;

	tmp = *array;
	while (len--)
	{
		if (*tmp == NULL)
			continue ;
		if (f == NULL)
			free(*tmp);
		else
			f(*tmp);
		++tmp;
	}
	free(*array);
	*array = NULL;
}
