/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:59:23 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/14 13:04:23 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	get_number(char number[4][4], unsigned int *i, unsigned int i2,
			char *copy)
{
	if (copy[*i] < '0' || copy[*i] > '9')
		return (printf("not int\n"), false);
	else if (*i > 3)
		return (printf("number too big\n"), false);
	number[i2][*i] = copy[*i];
	number[i2][*i + 1] = '\0';
	*i += 1;
	return (true);
}

static bool	check_color(char number[4][4], char *line)
{
	unsigned int	i;
	unsigned int	i2;
	char			*copy;

	i = 0;
	i2 = -1;
	copy = line;
	while (copy[i] && ++i2 < 3)
	{
		while (copy[i] && copy[i] != ',' && i < 3)
		{
			if (!get_number(number, &i, i2, copy))
				return (false);
		}
		if (i2 == 2)
			copy = copy + i;
		else
			copy = copy + i + 1;
		i = 0;
	}
	if (i2 < 2)
		return (printf("wrong color\n"), false);
	else if (copy[i] && copy[i] != '\n')
		return (printf("too many informations\n"), false);
	return (true);
}

bool	get_color(char *line, t_game *game, int key, unsigned char *octal)
{
	int		ret;
	char	number[4][4];

	ret = 0;
	if (!check_color(number, line))
		return (false);
	ret += (ft_atoi(number[0]) << 16);
	ret += (ft_atoi(number[1]) << 8);
	ret += ft_atoi(number[2]);
	if (key == KEY_C)
		game->c_color = ret;
	else if (key == KEY_F)
		game->f_color = ret;
	*octal = *octal + (1 << key);
	return (true);
}
