/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:21:17 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/10 13:21:18 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/builtins.h"

void	builtin_pwd(void)
{
	char	path[MAXPATHLEN];

	if (getcwd(path, MAXPATHLEN))
	{
		ft_printf("#!fd=2^getcwd() failed\n");
		return ;
	}
	ft_printf("%s\n", path);
}
