/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:48 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 18:23:24 by vchesnea         ###   ########.fr       */
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
		ft_printf("#!fd=2^%s: too few arguments\n", argv[0]);
		return ;
	}
	if (delete_var(argv[1]))
		ft_printf("#!fd=2^%s: %s\n", argv[0], get_error());
}
