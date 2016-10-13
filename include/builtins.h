/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 18:00:11 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/09 18:01:06 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	builtin_help(void);
void	builtin_pwd(void);
void	builtin_env(void);
void	builtin_setenv(int argc, char **argv);
void	builtin_unsetenv(int argc, char **argv);
void	builtin_cd(void);
void	builtin_exit(void);

#endif
