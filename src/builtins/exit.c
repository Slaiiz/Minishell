/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:37 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/09 17:11:38 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

/*
** Builtin command : exit
** Terminate the shell session.
*/

void	builtin_exit(int argc, char **argv)
{
	int	n;

	if (argc > 1)
		n = ft_atoi(argv[1]);
	exit(argc < 2 ? EXIT_SUCCESS : n);
}
