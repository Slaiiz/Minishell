/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:37 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 18:41:32 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

#include "vars.h"

/*
** Builtin command : exit
** Terminate the shell session.
*/

void	builtin_exit(int argc, char **argv)
{
	int	n;

	if (argc > 1)
		n = ft_atoi(argv[1]);
	free_vars();
	exit(argc < 2 ? EXIT_SUCCESS : n);
}
