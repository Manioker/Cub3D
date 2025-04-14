/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:13:15 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/14 13:05:35 by rothiery         ###   ########.fr       */
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

bool	valid_map(char **map, unsigned int i, unsigned int i2)
{
	if (i == 0 || (map[i - 1][i2] != '1' && map[i - 1][i2] != '0'
		&& map[i - 1][i2] != 'N' && map[i - 1][i2] != 'S'
		&& map[i - 1][i2] != 'E' && map[i - 1][i2] != 'W'))
		return (false);
	else if (i2 == 0 || (map[i][i2 - 1] != '1' && map[i][i2 + 1] != '0'
		&& map[i][i2 + 1] != 'N' && map[i][i2 + 1] != 'S'
		&& map[i][i2 + 1] != 'E' && map[i][i2 + 1] != 'W'))
		return (false);
	else if (i == arr_len(map) || (map[i + 1][i2] != '1'
		&& map[i + 1][i2] != '0'
		&& map[i + 1][i2] != 'N' && map[i + 1][i2] != 'S'
		&& map[i + 1][i2] != 'E' && map[i + 1][i2] != 'W'))
		return (false);
	else if ((int)i2 == ft_strlen(map[i]) || (map[i][i2 + 1] != '1'
		&& map[i][i2 + 1] != '0' && map[i][i2 + 1] != 'N'
		&& map[i][i2 + 1] != 'S' && map[i][i2 + 1] != 'E'
		&& map[i][i2 + 1] != 'W'))
		return (false);
	return (true);
}
