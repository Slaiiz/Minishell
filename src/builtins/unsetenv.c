/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:48 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/27 17:26:06 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

#include "error.h"
#include "vars.h"

/*
** Builtin command : unsetenv
** Deletes variable described by argv[1].
*/

void	builtin_unsetenv(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Too few arguments\n");
		return ;
	}
	if (delete_var(argv[1]))
		ft_printf("%s: %s\n", argv[0], get_error());
}
