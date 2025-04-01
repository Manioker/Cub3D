/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:08:59 by anvacca           #+#    #+#             */
/*   Updated: 2025/03/31 14:41:32 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycasting(t_mlx *mlx, t_game *game)
{
	int x;
	float	camerax;
	float	raydirx;
	float	raydiry;

	x = 0;
	while (x < WINDOW_X)
	{
		camerax = 2 * x / (float)WINDOW_X - 1;
		raydirx = game->dirx + game->planex * camerax;
		raydiry = game->diry + game->planey * camerax;
		x++;
	}
	
}
