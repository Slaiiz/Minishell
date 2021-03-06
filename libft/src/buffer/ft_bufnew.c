/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:41:13 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/14 14:34:37 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_buffer.h"

t_buff	*ft_bufnew(void)
{
	t_buff	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = NULL;
	new->size = 0;
	new->len = 0;
	return (new);
}
