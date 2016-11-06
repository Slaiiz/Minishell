/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:37:18 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/08 15:37:18 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libflag.h"

void	libflag_free(t_flaglist **list)
{
	t_flaglist	*next;

	while (*list != NULL)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
	*list = NULL;
}
