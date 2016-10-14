/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:34 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/09 17:11:35 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/builtins.h"

/*
** Builtin command : env
** Prints the list of environment variables on the standard output.
*/

void	builtin_env(void)
{
	const t_entry	*env;

	env = get_vars();
	while (env != NULL)
	{
		ft_printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}
