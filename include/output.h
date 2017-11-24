/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 13:41:17 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 16:15:10 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

/*
** Executed on command-line flag '-h --help', prints help and quits.
*/

void	print_help(void);

/*
** Executed on command-line flag '-v --version', prints build version.
** Only for the shows, ain't gonna change anytime soon.
*/

void	print_version(void);

/*
** Called each time to mark the beginning of a command.
** Prints a customizable prompt inherited from environment
** variable 'PS1'.
*/

void	print_prompt(void);

#endif
