/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:16:53 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 14:41:58 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_buffer.h"

void	ft_bufdel(t_buff **buf)
{
	if ((*buf)->data != NULL)
		free((*buf)->data);
	free(*buf);
	*buf = NULL;
	return ;
}
