/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:33:20 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/25 13:54:53 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*saveread(int fd, char *save)
{
	int		brd;
	char	*rd;

	brd = 1;
	rd = (char *)malloc(sizeof(char) * 11);
	if (rd == NULL)
		return (NULL);
	while (!(ft_strchr(save, '\n')) && brd > 0)
	{
		brd = read(fd, rd, 10);
		if (brd == -1)
			return (free(rd), free(save), NULL);
		rd[brd] = '\0';
		save = ft_strjoinfr(save, rd);
		if (save == NULL)
			return (free(rd), NULL);
	}
	if (brd == 0 && save[brd] == '\0')
		return (free(save), free(rd), NULL);
	return (free(rd), save);
}

char	*linesep(char *save)
{
	char	*line;
	int		i;

	i = 0;
	while (!(save[i] == '\n' || save[i] == '\0'))
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*saveend(char *save)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (save == NULL)
		return (NULL);
	while (!(save[i] == '\n' || save[i] == '\0'))
		i++;
	if (save[i] == '\0')
		return (free(save), NULL);
	i++;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(save)));
	if (temp == NULL)
		return (NULL);
	while (save[i])
	{
		temp[j] = save[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	return (free(save), temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0)
		return (NULL);
	if (save == NULL)
		save = ft_strdup("");
	save = saveread(fd, save);
	if (save == NULL)
		return (NULL);
	line = linesep(save);
	save = saveend(save);
	return (line);
}
