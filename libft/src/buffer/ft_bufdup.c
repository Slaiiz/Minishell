/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:03:51 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 18:19:24 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_buffer.h"

void	*ft_bufdup(t_buff *buf, size_t len)
{
	void	*new;

	new = malloc(sizeof(*new) * len);
	if (new == NULL)
		return (NULL);
	if (ft_bufsub(buf, new, len) == -1U)
	{
		free(new);
		return (NULL);
	}
	return (new);
}
