/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:29:42 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/20 10:29:43 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/parsing.h"

#include "error.h"

static int	read_quoted_string(const char **ptr, t_list **list)
{
	char		*string;
	const char	*tmp;
	t_list		*new;

	tmp = *ptr;
	while (*tmp != '\"' && *tmp != '\'')
		if (*tmp++ == '\0')
			return (set_error(ERR_WRONGQUOTING));
	if ((string = ft_strndup(*ptr, tmp - *ptr)) == NULL)
		return (set_error(ERR_NOMEMORY));
	if ((new = ft_lstnew(string, 0)) == NULL)
		return (set_error(ERR_NOMEMORY));
	ft_lstadd(list, new);
	*ptr = tmp + 1;
	return (0);
}

static int	read_single_word(const char **ptr, t_list **list)
{
	char		*string;
	const char	*tmp;
	t_list		*new;

	tmp = *ptr;
	while (*tmp != '\0' && !ft_isblank(*tmp) && *tmp != '\"')
		tmp++;
	if ((string = ft_strndup(*ptr, tmp - *ptr)) == NULL)
		return (set_error(ERR_NOMEMORY));
	if ((new = ft_lstnew(string, 0)) == NULL)
		return (set_error(ERR_NOMEMORY));
	ft_lstadd(list, new);
	*ptr = tmp;
	return (0);
}

/*
** Splits a string, with integrity of quoted texts preserved.
**  Returns an allocated string on success, or NULL on failure.
*/

t_list		*parse_input_string(const char *line)
{
	t_list	*output;

	while (ft_isblank(*line))
		++line;
	output = NULL;
	while (*line != '\0')
	{
		if ((*line == '\'' || *line == '\"') && line++)
		{
			if (read_quoted_string(&line, &output))
				return (NULL);
		}
		else if (read_single_word(&line, &output))
			return (NULL);
		while (ft_isblank(*line))
			line++;
	}
	while (output != NULL)
	{
		ft_printf("> %s\n", output->content);
		output = output->next;
	}
	return (output);
}
