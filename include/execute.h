/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 18:00:11 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/09 18:01:06 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

void	initialize_builtins(void);

int		execute_builtin(int argc, char **argv);

int		execute_binary(int argc, char **argv, char **envp);

#endif
