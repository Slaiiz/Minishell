/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:31 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/25 10:56:07 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

#include "error.h"
#include "vars.h"

static int	validate(const char *target)
{
	struct stat	stats;

	if (stat(target, &stats))
		return (set_error(ERR_FILENOTFOUND, target));
	if (!S_ISDIR(stats.st_mode))
		return (set_error(ERR_NOTDIRECTORY, target));
	if (access(target, X_OK))
		return (set_error(ERR_NOPERMISSION, target));
	return (0);
}

static int	transition(const char *target)
{
	char		path[MAXPATHLEN];
	const char	*oldpwd;

	oldpwd = get_var("PWD");
	if (validate(target))
		return (1);
	if (chdir(target))
		return (set_error(ERR_CHDIRFAILED));
	if (getcwd(path, MAXPATHLEN) == NULL)
		return (set_error(ERR_GETCWDFAILED));
	if (set_var("OLDPWD", oldpwd))
		return (1);
	if (set_var("PWD", path))
		return (1);
	return (0);
}

/*
** Builtin command : cd
** Changes the current directory.
*/

void		builtin_cd(int argc, char **argv)
{
	const char	*target;

	if (argc < 2)
		target = get_var("HOME");
	else if (ft_strequ(argv[1], "-"))
		target = get_var("OLDPWD");
	else
		target = argv[1];
	if (transition(target))
	{
		ft_printf("#!fd=2^%s: %s\n",
			argv[0], get_error());
		return ;
	}
}
