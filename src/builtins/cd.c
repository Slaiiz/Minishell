/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:31 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 13:34:48 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

#include "error.h"
#include "vars.h"

static int	validate(const char *path)
{
	struct stat	stats;

	if (stat(path, &stats))
		return (set_error(ERR_FILENOTFOUND, path));
	if (!S_ISDIR(stats.st_mode))
		return (set_error(ERR_NOTDIRECTORY, path));
	if (access(path, X_OK))
		return (set_error(ERR_NOPERMISSION, path));
	return (0);
}

/*
** Builtin command : cd
** Changes the current directory.
*/

void		builtin_cd(int argc, char **argv)
{
	char		path[MAXPATHLEN];
	const char	*target;
	const char	*oldpwd;

	if (argc < 2)
		target = get_var("HOME");
	else if (ft_strequ(argv[1], "-"))
		target = get_var("OLDPWD");
	else
		target = argv[1];
	if (validate(target))
	{
		ft_printf("#!fd=2^%s: %s\n",
			argv[0], get_error());
		return ;
	}
	oldpwd = get_var("PWD");
	chdir(target);
	getcwd(path, MAXPATHLEN);
	set_var("OLDPWD", oldpwd);
	set_var("PWD", path);
}
