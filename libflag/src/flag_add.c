/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:37:23 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/11 16:46:53 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libflag.h"

/*
** Appends a new flag definition to an existing flag list.
**  Returns FLAG_ERROR_OK on success, or any other value on failure.
*/

int	flag_add(t_flaglist **out, const char *flag,
			t_flagtype type, void *data)
{
	t_flaglist	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (FLAG_ERROR_MALLOC);
	if (ft_expect(&flag, "$i:$i",
			&new->fast, &new->slow))
		return (FLAG_ERROR_BADSYNTAX);
	new->type = type;
	new->data = data;
	new->next = *out;
	*out = new;
	return (FLAG_ERROR_OK);
}
