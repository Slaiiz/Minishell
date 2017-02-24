/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:55:21 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/11 18:04:46 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/btree.h"

static void	recurse(t_btree **node, void (*f)(void*))
{
	if (node->left)
	{
		recurse(node->left);
		free(node->left);
	}
	if (node->right)
	{
		recurse(node->right);
		free(node->right);
	}
	f(node->data);
	free(node);
}

void		ft_btreedel(t_btree **btree, void (*f)(void*))
{
	recurse(*btree);
	*btree = NULL;
}
