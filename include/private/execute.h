/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:35:52 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/30 10:04:42 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define DEFINE_BUILTIN(a, b, c) (a).name = (b); (a).func = (c)

# include <stdlib.h>
# include <unistd.h>
# include <sys/param.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

# include "../error.h"
# include "../helpers.h"
# include "../vars.h"

typedef struct	s_builtin
{
	char const	*name;
	void		(*func)(int argc, char **argv);
}				t_builtin;

/*
** Builtin command : cd
** Changes the current directory.
*/

void			builtin_cd(int argc, char **argv);

/*
** Builtin command : env
** Prints the list of environment variables on the standard output.
*/

void			builtin_env(int argc, char **argv);

/*
** Builtin command : exit
** Terminate the shell session.
*/

void			builtin_exit(int argc, char **argv);

/*
** Builtin command : help
** Prints shell help on the standard output.
*/

void			builtin_help(int argc, char **argv);

/*
** Builtin command : pwd
** Prints the working directory on the standard output.
*/

void			builtin_pwd(int argc, char **argv);

/*
** Builtin command : setenv
** Sets variable described by argv[1] with value argv[2].
** If no argument given :
** Prints the list of environment variables on the standard output.
*/

void			builtin_setenv(int argc, char **argv);

/*
** Builtin command : unsetenv
** Deletes variable described by argv[1].
*/

void			builtin_unsetenv(int argc, char **argv);

#endif
