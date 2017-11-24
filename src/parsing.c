/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:29:42 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 16:40:18 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/parsing.h"

#include "error.h"
#include "helpers.h"
#include "vars.h"

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

static int	read_tilde_operator(const char **str, char **out)
{
	const char	*tmp;

	tmp = *str + 1;
	while (*tmp != '\'' && *tmp != '\"')
	{
		if (*tmp == '\0' || ft_isblank(*tmp))
			break ;
		++tmp;
	}
	*out = ft_strnew(tmp - *str + ft_strlen(get_var("HOME")));
	if (*out == NULL)
		return (set_error(ERR_NOMEMORY));
	ft_strcat(*out, get_var("HOME"));
	ft_strncat(*out, *str + 1, tmp - (*str + 1));
	*str = tmp;
	return (0);
}

static int	read_single_word(const char **str, char **out)
{
	const char	*tmp;

	tmp = *str;
	if (*tmp == '~' && is_valid_tilde(tmp))
		return (read_tilde_operator(str, out));
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
		if (ft_isblank(*str) && ++str)
			continue ;
		if (*str == '\'' || *str == '\"')
		{
			if (read_quoted_string(&str, &tmp))
				return (NULL);
		}
		else if (read_single_word(&str, &tmp))
			return (NULL);
		new = ft_lstnew(tmp, ft_strlen(tmp));
		if (new == NULL)
			return (NULL);
		ft_lstadd(&out, new);
	}
	return (turn_into_array(&out));
}
