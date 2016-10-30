/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:34 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/27 15:01:12 by vchesnea         ###   ########.fr       */
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
** Builtin command : env
** Prints the list of environment variables on the standard output.
*/

void		builtin_env(int argc, char **argv)
{
	const t_entry	*env;

	env = get_vars();
	recurse(env);
	if (argc)
		++argv;
}
