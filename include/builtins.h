/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 18:00:11 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/09 18:01:06 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

static t_builtin	g_builtins[NUMBUILTINS + 1];

static int			register_builtin(char const *name, void(*func)(void))
{

}

int					initialize_builtins(void)
{
	g_builtins[NUMBUILTINS] = NULL;
	REGISTER_BUILTINS();
	return (0);
}

#endif
