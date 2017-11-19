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

# define ERR_NOMEMORY      "memory allocation failed"
# define ERR_WAITFAILED    "failed to wait for child process"
# define ERR_NOPERMISSION  "permission denied: %s"
# define ERR_FILENOTFOUND  "no such file or directory: %s"
# define ERR_VARNOTFOUND   "no such variable: %s"
# define ERR_CMDNOTFOUND   "command not found: %s"
# define ERR_UNKNOWNFLAG   "unrecognized flag"
# define ERR_BADFLAGSTX    "bad flag syntax"
# define ERR_SIGNALFAILED  "could not setup signals"
# define ERR_MALFORMEDKV   "malformed key/value pair"
# define ERR_STATFAILED    "could not stat() file: %s"
# define ERR_ISDIRECTORY   "file is directory: %s"

/*
** Returns the last error in the form on a string.
*/

char const	*get_error(void);

/*
** Sets the error active flag accompanied with a description string.
*/

int			set_error(char const *string, ...);

#endif
