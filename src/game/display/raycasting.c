/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:08:59 by anvacca           #+#    #+#             */
/*   Updated: 2025/04/01 14:19:14 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perform_ray(t_game *game)
{
	if (game->raydirx < 0)
	{
		game->stepx = -1;
		game->sidedistx = (game->posx - game->mapx) * game->deltadistx;
	}
	else
	{
		game->stepx = 1;
		game->sidedistx = (game->mapx + 1.0 - game->posx) * game->deltadistx;
	}
	if (game->raydiry < 0)
	{
		game->stepy = -1;
		game->sidedisty = (game->posy - game->mapy) * game->deltadisty;
	}
	else
	{
		game->stepy = 1;
		game->sidedisty = (game->mapy + 1.0 - game->posy) * game->deltadisty;
	}
}

void	perform_dda(t_game *game)
{
	game->hit = 0;
	while (game->hit == 0)
	{
		if (game->sidedistx < game->sidedisty)
		{
			game->sidedistx += game->deltadistx;
			game->mapx += game->stepx;
			game->side = 0;
		}
		else
		{
			game->sidedisty += game->deltadisty;
			game->mapy += game->stepy;
			game->side = 1;
		}
		if (game->map[game->mapy][game->mapx] == '1')
			break ;
	}
}

void	calculate_wall(t_game *game)
{
	if (game->side == 0)
		game->perpwalldist = (game->mapx - game->posx + (1 - game->stepx) / 2)
			/ game->raydirx;
	else
		game->perpwalldist = (game->mapy - game->posy + (1 - game->stepy) / 2)
			/ game->raydiry;
	game->lineheigth = (int)(WINDOW_Y / game->perpwalldist);
	game->drawstart = -game->lineheigth / 2 + WINDOW_Y / 2;
	if (game->drawstart < 0)
		game->drawstart = 0;
	game->drawend = game->lineheigth / 2 + WINDOW_Y / 2;
	if (game->drawend >= WINDOW_Y)
		game->drawend = WINDOW_Y - 1;
}

static void caca(t_game *game, t_mlx *mlx, int x)
{
	int y = game->drawstart;
	while (y < game->drawend)
	{
		if (game->side == 1)
			*(unsigned int *)(mlx->data.addr + (y * mlx->data.line_length + x
				* (mlx->data.bits_per_pixel / 8))) = 0x0000FF;
		else
			*(unsigned int *)(mlx->data.addr + (y * mlx->data.line_length + x
					* (mlx->data.bits_per_pixel / 8))) = 0x6060FF;
		y++;
	}
}

void	raycasting(t_mlx *mlx, t_game *game)
{
	int		x;
	float	camerax;

	x = 0;
	while (x < WINDOW_X)
	{
		camerax = 2 * x / (float)WINDOW_X - 1;
		game->raydirx = game->dirx + game->planex * camerax;
		game->raydiry = game->diry + game->planey * camerax;
		game->deltadistx = fabs(1 / game->raydirx);
		game->deltadisty = fabs(1 / game->raydiry);
		game->mapx = (int)game->posx;
		game->mapy = (int)game->posy;
		perform_ray(game);
		perform_dda(game);
		calculate_wall(game);
		caca(game, mlx, x);
		x++;
	}
}
