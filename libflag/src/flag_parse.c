/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:37:10 by vchesnea          #+#    #+#             */
/*   Updated: 2017/01/02 16:40:32 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libflag.h"

static int	evaluate_flag(t_flaglist *list, char *arg)
{
	if (list->type == FLAG_TYPE_SWITCH)
		*((int*)list->data) = 1;
	else if (list->type == FLAG_TYPE_VALUE)
	{
		if (ft_expect((const char **)&arg, "=$nw", (int*)list->data))
			return (FLAG_ERROR_BADSYNTAX);
	}
	else if (list->type == FLAG_TYPE_HOOK)
		((void(*)(void))list->data)();
	return (FLAG_ERROR_OK);
}

static int	parse_slow(t_flaglist *list, char *arg)
{
	while (list != NULL)
	{
		if (!ft_expect((const char **)&arg, list->slow))
			return (evaluate_flag(list, arg));
		list = list->next;
	}
	if (list == NULL)
		return (FLAG_ERROR_NOMATCH);
	return (FLAG_ERROR_OK);
}

static int	parse_fast(t_flaglist *list, char *arg)
{
	int			error;
	t_flaglist	*base;

	while (arg[0] != '\0')
	{
		base = list;
		while (base != NULL)
		{
			if (base->fast == arg[0])
			{
				error = evaluate_flag(base, arg);
				if (error != FLAG_ERROR_OK)
					return (error);
				break ;
			}
			base = base->next;
		}
		if (base == NULL)
			return (FLAG_ERROR_NOMATCH);
		++arg;
	}
	return (FLAG_ERROR_OK);
}

int			flag_parse(t_flaglist *list, int argc, char **argv)
{
	int		error;
	char	*arg;

	while (--argc > 0)
	{
		arg = *++argv;
		if (arg[0] != '-')
			break ;
		if (arg[1] == '-')
		{
			error = parse_slow(list, &arg[2]);
			if (error != FLAG_ERROR_OK)
				return (error);
			continue ;
		}
		error = parse_fast(list, &arg[1]);
		if (error != FLAG_ERROR_OK)
			return (error);
	}
	return (FLAG_ERROR_OK);
}
