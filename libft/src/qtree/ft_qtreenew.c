/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qtreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 13:12:49 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/11 17:50:45 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_qtree.h"

t_qtree	*ft_qtreenew(int x, int y, void *data)
{
	t_qtree	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	bzero(new, sizeof(new));
	new->data = data;
	new->parent = NULL;
	return (new);
}
