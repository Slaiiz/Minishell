/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:11:48 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/09 17:11:48 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/builtins.h"

void	builtin_unsetenv(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Too few arguments\n");
		return ;
	}
	delete_var(argv[1]);
}
