/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:31 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/23 16:40:28 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

#include "error.h"
#include "vars.h"

static int	validate(char *exec, char *path)
{
	struct stat	stats;

	if (stat(path, &stats))
	{
		ft_printf("#!fd=2^%s: no such file or directory: %s\n",
			exec, path);
		return (1);
	}
	if (!S_ISDIR(stats.st_mode))
	{
		ft_printf("#!fd=2^%s: not a directory: %s\n",
			exec, path);
		return (1);
	}
	return (0);
}

/*
** Builtin command : cd
** Changes the current directory.
*/

void		builtin_cd(int argc, char **argv)
{
	char		path[MAXPATHLEN];
	char const	*target;
	char const	*oldpwd;

	if (argc < 2)
		target = get_var("HOME");
	else if (ft_strequ(argv[1], "-"))
		target = get_var("OLDPWD");
	else if (!validate(argv[0], argv[1]))
		target = argv[1];
	else
		return ;
	oldpwd = get_var("PWD");
	if (chdir(target))
	{
		ft_printf("#!fd=2^%s: could not chdir()\n");
		return ;
	}
	getcwd(path, MAXPATHLEN);
	set_var("OLDPWD", oldpwd);
	set_var("PWD", path);
}
