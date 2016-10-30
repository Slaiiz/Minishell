/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:31 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/30 11:02:08 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

/*
** Builtin command : cd
** Changes the current directory.
*/

void	builtin_cd(int argc, char **argv)
{
	if (argc < 2)
		return ;
	if (chdir(argv[1]))
		ft_printf("#!fd=2^cd: no such file or directory: %s\n", argv[1]);
}
