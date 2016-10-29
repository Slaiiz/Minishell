/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:21:17 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/29 18:56:12 by vchesnea         ###   ########.fr       */
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
		ft_printf("#!fd=2^getcwd() failed\n");
		return ;
	}
	if (argc)
		++argv;
	ft_printf("%s\n", path);
}
