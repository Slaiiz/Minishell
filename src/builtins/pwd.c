/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:21:17 by vchesnea          #+#    #+#             */
/*   Updated: 2017/01/02 15:42:25 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

/*
** Builtin command : pwd
** Prints the working directory on the standard output.
*/

void	builtin_pwd(int argc, char **argv)
{
	char	path[MAXPATHLEN];

	if (getcwd(path, MAXPATHLEN) == NULL)
	{
		ft_printf("#!fd=2^%s: getcwd() failed\n", argv[0]);
		return ;
	}
	if (argc)
		++argv;
	ft_printf("%s\n", path);
}
