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

#include <stdlib.h>
#include "libft.h"

#include "builtins.h"

void	help(void)
{
	ft_printf("Usage: ./minishell [-h] [--help]\n");
	exit(EXIT_SUCCESS);
}
