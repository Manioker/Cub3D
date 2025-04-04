/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:34:17 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/01 10:43:46 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (s + i);
		}
		i++;
	}
	if (c == s[i])
	{
		return (s + i);
	}
	return (NULL);
}

char	*ft_strjoinfr(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	s1l;

	s1l = ft_strlen(s1);
	i = 0;
	dest = malloc(sizeof(char) * (s1l + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (i < s1l)
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < (s1l + ft_strlen(s2)))
	{
		dest[i] = s2[i - s1l];
		i++;
	}
	dest[i] = '\0';
	return (free((char *)s1), dest);
}

char	*ft_strdup(char *str)
{
	unsigned int	i;
	char			*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
