/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:26:49 by vchesnea          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft.h"

t_buff	*ft_bufnew(size_t size)
{
	t_buff	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = malloc(size);
	if (new->data == NULL)
	{
		free(new);
		return (NULL);
	}
	new->size = size;
	new->len = 0;
	return (new);
}
