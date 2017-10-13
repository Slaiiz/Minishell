/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:31 by vchesnea          #+#    #+#             */
/*   Updated: 2017/10/10 17:47:21 by vchesnea         ###   ########.fr       */
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
	char		path[MAXPATHLEN];
	struct stat	stats;

	if (argc < 2)
		return ;
	if (stat(argv[1], &stats))
	{
		ft_printf("#!fd=2^%s: no such file or directory: %s\n",
			argv[0], argv[1]);
		return ;
	}
	if (!S_ISDIR(stats.st_mode))
	{
		ft_printf("#!fd=2^%s: not a directory: %s\n",
			argv[0], argv[1]);
		return ;
	}
	chdir(argv[1]);
	getcwd(path, MAXPATHLEN);
	if (set_var("PWD", path))
	{
		ft_printf("#!fd=2^%s: %s\n", argv[0], get_error());
		return ;
	}
}
