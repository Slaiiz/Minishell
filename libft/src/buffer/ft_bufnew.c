/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:41:13 by vchesnea          #+#    #+#             */
/*   Updated: 11/6/2016, 4:47:12 PM by vchesnea       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_buffer.h"

t_buff	*ft_bufnew(void)
{
	t_buff	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = malloc(0);
	if (new->data == NULL)
	{
		free(new);
		return (NULL);
	}
	new->size = 0;
	new->len = 0;
	return (new);
}
