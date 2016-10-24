/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:09:56 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/09 17:10:11 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

/*
** Builtin command : help
** Prints shell help on the standard output.
*/

void	builtin_help(int argc, char **argv)
{
	if (argc)
		++argv;
	ft_printf("Usage: ./minishell [-h] [--help]\n");
}
