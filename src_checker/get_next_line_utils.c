/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:20:56 by yanflous          #+#    #+#             */
/*   Updated: 2024/11/21 10:22:59 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strchr(const char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (c == '\0')
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	size_t	s_len;
	size_t	i;
	char	*ptr;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	ptr = malloc(sizeof(char) * (s_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s_len > i)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	size_t	s1_len;
	char	*ptr;
	size_t	i;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (start >= s1_len)
		return (ft_strdup(""));
	if (len > s1_len - start)
		len = s1_len - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
