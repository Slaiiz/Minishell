/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:37:23 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/08 15:37:24 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <private/libflag.h>

int	flag_add(t_flaglist **out, const char fast, const char *slow,
			t_flagtype type, void *data)
{
	t_flaglist	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (FLAG_ERROR_MALLOC);
	new->fast = fast;
	new->slow = slow;
	new->type = type;
	new->data = data;
	new->next = *out;
	*out = new;
	return (FLAG_ERROR_OK);
}
