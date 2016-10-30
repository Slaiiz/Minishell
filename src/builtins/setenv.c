/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:44 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/27 17:06:43 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

#include "vars.h"

static void	recurse(const t_entry *env)
{
	if (env->next)
		recurse(env->next);
	ft_printf("%s=%s\n", env->key, env->value);
}

/*
** Builtin command : setenv
** Sets variable described by argv[1] with value argv[2].
** If no argument given :
** Prints the list of environment variables on the standard output.
*/

void		builtin_setenv(int argc, char **argv)
{
	const t_entry	*env;

	if (argc < 2)
	{
		env = get_vars();
		recurse(env);
		return ;
	}
	set_var(argv[1], argc < 3 ? "" : argv[2]);
}
