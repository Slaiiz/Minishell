/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:08 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/14 14:49:09 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

/*
** Builtin command : echo
** Writes the concatenated arguments to the standard output.
*/

void	builtin_echo(int argc, char **argv)
{
	while (argc > 1)
	{
		if (argc > 2)
			ft_printf("%s ", *++argv);
		else
			ft_printf("%s", *++argv);
		--argc;
	}
	ft_printf("\n");
}
