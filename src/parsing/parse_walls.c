/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:28:38 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/10 14:34:23 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	key_find(char *line)
{
	unsigned int	i;

	i = 0;
	if (!line || *line == '\0' || *line == '\n')
		return (EMPTY);
	while (line[i] == ' ')
		i++;
	if (!ft_strncmp(line + i, "NO", 2))
		return (KEY_NO);
	else if (!ft_strncmp(line + i, "SO", 2))
		return (KEY_SO);
	else if (!ft_strncmp(line + i, "EA", 2))
		return (KEY_EA);
	else if (!ft_strncmp(line + i, "WE", 2))
		return (KEY_WE);
	else if (!ft_strncmp(line + i, "C", 1))
		return (KEY_C);
	else if (!ft_strncmp(line + i, "F", 1))
		return (KEY_F);
	return (ERR);
}

static bool	set_fd2(unsigned int key, int fd, t_game *game, unsigned char *octal)
{
	if (fd <= 0)
		return (false);
	if (((*octal << key) & 1) == 1)
		return (printf("already defined\n"), false);
	else if (key == KEY_NO)
		game->no_fd = fd;
	else if (key == KEY_SO)
		game->so_fd = fd;
	else if (key == KEY_EA)
		game->ea_fd = fd;
	else if (key == KEY_WE)
		game->we_fd = fd;
	*octal = *octal + (1 << key);
	return (true);
}

static bool	set_fd(unsigned int key, char *line, t_game *game, unsigned char *octal)
{
	unsigned int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (key == KEY_C || key == KEY_F)
	{
		i++;
		while (line[i] == ' ')
			i++;
		return (ft_getcolor(line + i, game, key, octal));
	}
	else
	{
		i += 2;
		while (line[i] == ' ')
			i++;
		return (set_fd2(key, open(line + i, O_RDONLY), game, octal));
	}
}

static void	init_game(t_game *game)
{
	game->no_fd = 0;
	game->so_fd = 0;
	game->ea_fd = 0;
	game->we_fd = 0;
}

bool	parse_walls(int fd, t_game *game)
{
	char			*line;
	unsigned int	key;
	unsigned char	octal;

	init_game(game);
	octal = 0;
	line = get_next_line(fd);
	while (line)
	{
		key = key_find(line);
		if (key == ERR)
			return (printf("ERR\n"), free(line), false);
		else if (key != EMPTY && !set_fd(key, line, game, &octal))
			return (printf("ERR2\n"), free(line), false);
		line = get_next_line(fd);
		if (octal == 126)
			return (true);
	}
	return (false);
}
