/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:13:15 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/25 13:08:54 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	arr_len(char **map)
{
	unsigned int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

bool	valid_map(char **map, unsigned int y, unsigned int x)
{
	if (y == 0 || (map[y - 1][x] != '1' && map[y - 1][x] != '0'
		&& map[y - 1][x] != 'N' && map[y - 1][x] != 'S'
		&& map[y - 1][x] != 'E' && map[y - 1][x] != 'W'))
		return (false);
	else if (x == 0 || (map[y][x + 1] != '1' && map[y][x + 1] != '0'
		&& map[y][x + 1] != 'N' && map[y][x + 1] != 'S'
		&& map[y][x + 1] != 'E' && map[y][x + 1] != 'W'))
		return (false);
	else if (y == arr_len(map) - 1 || (map[y + 1][x] != '1'
		&& map[y + 1][x] != '0'
		&& map[y + 1][x] != 'N' && map[y + 1][x] != 'S'
		&& map[y + 1][x] != 'E' && map[y + 1][x] != 'W'))
		return (false);
	else if ((int)x == ft_strlen(map[y]) || (map[y][x - 1] != '1'
		&& map[y][x - 1] != '0' && map[y][x - 1] != 'N'
		&& map[y][x - 1] != 'S' && map[y][x - 1] != 'E'
		&& map[y][x - 1] != 'W'))
		return (false);
	return (true);
}
