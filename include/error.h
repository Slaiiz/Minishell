/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:43:33 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 17:42:08 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
** Returns the last error in the form on a string.
*/

char const	*get_error(void);

/*
** Sets the error active flag accompanied with a description string.
*/

int			set_error(char const *string, ...);

#endif
