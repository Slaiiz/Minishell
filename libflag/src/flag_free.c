/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:37:18 by vchesnea          #+#    #+#             */
/*   Updated: 2017/06/21 14:33:03 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libflag.h"

/*
** Frees a given list of flags generated previously
** by libflag, zeroing its pointer before returning.
*/

void	flag_free(t_flaglist **list)
{
	t_flaglist	*next;

	while (*list != NULL)
	{
		next = (*list)->next;
		free((*list)->slow);
		free((*list)->fast);
		free(*list);
		*list = next;
	}
	*list = NULL;
}
