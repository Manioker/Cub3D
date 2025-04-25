/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:51:26 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/25 12:33:53 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	skip_nl(int fd, char **line)
{
	unsigned int	i;

	i = 0;
	*line = get_next_line(fd);
	while (*line)
	{
		if (**line != '\n' && **line != '\0')
			return (true);
		free(*line);
		*line = get_next_line(fd);
	}
	return (printf("no map\n"), false);
}

static bool	is_map(char *line)
{
	unsigned int	i;

	i = 0;
	while (line[i] != 0 && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
			return (printf("invalid char\n"), false);
		i++;
	}
	return (true);
}

static char	**get_array(unsigned int i, char **old, char *line)
{
	unsigned int	i2;
	char			**ret;

	i2 = 0;
	ret = malloc(sizeof(char *) * (i + 2));
	while (i2 < i)
	{
		ret[i2] = old[i2];
		i2++;
	}
	ret[i2] = line;
	ret[i2 + 1] = NULL;
	free(old);
	return (ret);
}

static bool	check_map(char **map, t_game *game)
{
	unsigned int	y;
	unsigned int	x;
	bool			player_def;

	y = -1;
	player_def = false;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0' && !valid_map(map, y, x))
				return (false);
			else if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (player_def)
					return (printf("many players set\n"), false);
				set_pose(game, &player_def, y, x);
			}
		}
	}
	return (true);
}

bool	parse_map(int fd, t_game *game)
{
	char			*line;
	unsigned int	i;
	char			**map;

	i = 0;
	map = NULL;
	if (!skip_nl(fd, &line))
		return (false);
	while (line)
	{
		if (!is_map(line))
			return (false);
		else
			map = get_array(i, map, line);
		i++;
		line = get_next_line(fd);
	}
	check_map(map, game);
	game->map = map;
	return (true);
}
