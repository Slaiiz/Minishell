/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:35:52 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/10 18:35:53 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/param.h>
# include "libft.h"

# include "../error.h"
# include "../vars.h"

typedef struct	s_builtin
{
	char const	*name;
	void		*func;
}				t_builtin;

/*
** Builtin command : cd
** Changes the current directory.
*/

void			builtin_cd(void);

/*
** Builtin command : env
** Prints the list of environment variables on the standard output.
*/

void			builtin_env(void);

/*
** Builtin command : exit
** Terminate the shell session.
*/

void			builtin_exit(void);

/*
** Builtin command : help
** Prints shell help on the standard output.
*/

void			builtin_help(void);

/*
** Builtin command : pwd
** Prints the working directory on the standard output.
*/

void			builtin_pwd(void);

/*
** Builtin command : setenv
** Sets variable argv[1] with value argv[2].
** If no argument given :
** Prints the list of environment variables on the standard output.
*/

void			builtin_setenv(int argc, char **argv);

/*
** Builtin command : unsetenv
** Deletes variable argv[1].
*/

void			builtin_unsetenv(int argc, char **argv);

#endif
