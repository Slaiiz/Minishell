/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:09:56 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 18:24:28 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

/*
** Builtin command : help
** Prints shell help on the standard output.
*/

void	builtin_help(int argc, char **argv)
{
	if (argc)
		++argv;
	ft_printf("echo, cd, env, exit, help, pwd, setenv, unsetenv\n");
}
