/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:13:00 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 14:59:36 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_list.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*out;

	if ((out = malloc(sizeof(t_list))) == NULL)
		return ((t_list*)NULL);
	out->content = (void*)content;
	if (content == NULL)
		out->content_size = 0;
	else
		out->content_size = content_size;
	out->next = NULL;
	return (out);
}
