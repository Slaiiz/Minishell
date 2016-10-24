/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:44 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/09 17:11:44 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

/*
** Builtin command : setenv
** Sets variable described by argv[1] with value argv[2].
** If no argument given :
** Prints the list of environment variables on the standard output.
*/

void	builtin_setenv(int argc, char **argv)
{
	const t_entry	*env;

	if (argc < 2)
	{
		env = get_vars();
		while (env != NULL)
		{
			ft_printf("%s=%s\n", env->key, env->value);
			env = env->next;
		}
		return ;
	}
	ft_printf("%s\n%s\n", argv[1], argv[2]);
	set_var(argv[1], argc < 3 ? "" : argv[2]);
}
