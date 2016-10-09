/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:58:12 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/08 18:59:55 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

int		get_var(const char *key, const char **out);

int		set_var(const char *key, const char *value);

int		delete_var(const char *key);

void	free_vars(void);

#endif
