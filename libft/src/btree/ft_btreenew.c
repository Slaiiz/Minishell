/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:55:23 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/11 17:55:29 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/btree.h"

t_btree	*ft_btreenew(const void *data)
{
	t_btree	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = new;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;
	return (new);
}
