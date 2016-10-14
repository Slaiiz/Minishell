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

#include "private/builtins.h"

/*
** Builtin command : exit
** Terminate the shell session.
*/

void	builtin_exit(void)
{
	exit(EXIT_SUCCESS);
}
