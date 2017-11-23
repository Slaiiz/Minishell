/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:29:42 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/23 18:13:21 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/parsing.h"

#include "error.h"

static int	read_quoted_string(const char **str, char **out)
{
	const char	*tmp;

	if (**str == '\"' && (tmp = ++(*str)))
	{
		while (*tmp != '\"')
			if (*tmp++ == '\0')
				return (set_error(ERR_EXPECTTOKEN, "\""));
	}
	else if (**str == '\'' && (tmp = ++(*str)))
	{
		while (*tmp != '\'')
			if (*tmp++ == '\0')
				return (set_error(ERR_EXPECTTOKEN, "\'"));
	}
	*out = ft_strndup(*str, tmp - *str);
	if (*out == NULL)
		return (set_error(ERR_NOMEMORY));
	*str = tmp + 1;
	return (0);
}

/*
** TODO: Substitute tildes here.
*/

static int	read_single_word(const char **str, char **out)
{
	const char	*tmp;

	tmp = *str;
	while (*tmp != '\'' && *tmp != '\"')
	{
		if (*tmp == '\0' || ft_isblank(*tmp))
			break ;
		++tmp;
	}
	*out = ft_strndup(*str, tmp - *str);
	if (*out == NULL)
		return (set_error(ERR_NOMEMORY));
	*str = tmp;
	return (0);
}

static char	**turn_into_array(t_list **str)
{
	char	**out;
	t_list	*ptr;
	int		tmp;

	ptr = *str;
	tmp = ft_lstlen(ptr) + 1;
	out = malloc(sizeof(char*) * tmp);
	if (out == NULL)
		return (NULL);
	out[--tmp] = NULL;
	while (tmp--)
	{
		out[tmp] = ptr->content;
		ptr = ptr->next;
	}
	ft_lstdel(str, NULL);
	return (out);
}

/*
** Splits a string, with integrity of quoted texts preserved.
**  Returns an allocated string on success, or NULL on failure.
*/

char		**parse_input_string(const char *str)
{
	char	*tmp;
	t_list	*out;
	t_list	*new;

	out = NULL;
	while (*str != '\0')
	{
		while (ft_isblank(*str))
			++str;
		if (*str == '\'' || *str == '\"')
		{
			if (read_quoted_string(&str, &tmp))
				return (NULL);
		}
		else if (*str == '\0')
			break ;
		else if (read_single_word(&str, &tmp))
			return (NULL);
		new = ft_lstnew(tmp, ft_strlen(tmp));
		if (new == NULL)
			return (NULL);
		ft_lstadd(&out, new);
	}
	return (turn_into_array(&out));
}
