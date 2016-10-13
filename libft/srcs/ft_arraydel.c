/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:46:13 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/23 15:50:51 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft.h"

void	ft_arraydel(void ***array)
{
	void	**tmp;

	tmp = *array;
	while (**array != NULL)
		free(*(*array)++);
	*array = NULL;
	free(tmp);
}
