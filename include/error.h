/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:43:33 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/04 16:09:17 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
** Returns the last error in the form on a string.
*/

const char	*get_error(void);

/*
** Sets the error active flag accompanied with a description string.
*/

int			set_error(const char *string, ...);

#endif
