/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:31 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 17:42:27 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

#include "error.h"
#include "vars.h"

/*
** Builtin command : cd
** Changes the current directory.
*/

void	builtin_cd(int argc, char **argv)
{
	char	path[MAXPATHLEN];

	if (argc < 2)
		return ;
	if (chdir(argv[1]))
	{
		ft_printf("#!fd=2^%s: no such file or directory: %s\n",
			argv[0], argv[1]);
		return ;
	}
	if (getcwd(path, MAXPATHLEN) == NULL)
	{
		ft_printf("#!fd=2^getcwd() failed\n");
		return ;
	}
	if (set_var("PWD", path))
	{
		ft_printf("#!fd=2^%s: %s\n", argv[0], get_error());
		return ;
	}
}
