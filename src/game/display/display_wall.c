/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:08:06 by anvacca           #+#    #+#             */
/*   Updated: 2025/04/09 17:39:48 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_wall_side(t_game *game)
{
	if (game->side == 0)
	{
		if (game->raydirx < 0)
			game->find_texture = 2;
		else
			game->find_texture = 3;
	}
	else
	{
		if (game->raydiry < 0)
			game->find_texture = 0;
		else
			game->find_texture = 1;
	}
}

int	find_texture_x(t_mlx *mlx, t_game *game)
{
	int		texture_x;
	float	wallx;

	if (game->side == 0)
		wallx = game->posy + game->perpwalldist * game->raydiry;
	else
		wallx = game->posx + game->perpwalldist * game->raydirx;
	wallx -= floorf(wallx);
	texture_x = (int)(wallx * (float)mlx->texture[game->find_texture].width);
	if (game->side == 0 && game->raydirx > 0)
		texture_x = mlx->texture[game->find_texture].width - texture_x - 1;
	if (game->side == 1 && game->raydiry < 0)
		texture_x = mlx->texture[game->find_texture].width - texture_x - 1;
	return (texture_x);
}

void	display_wall(t_mlx *mlx, t_game *game, unsigned int x)
{
	int	y;
	int	color;
	int	offset;

	find_wall_side(game);
	game->texture_x = find_texture_x(mlx, game);
	game->step = (float)mlx->texture[game->find_texture].height
		/ game->lineheigth;
	game->texture_pos = (game->drawstart - WINDOW_Y / 2 + game->lineheigth / 2)
		* game->step;
	y = game->drawstart;
	while (y < game->drawend)
	{
		game->texture_y = (int)game->texture_pos % (mlx->texture[game->find_texture].height
				- 1);
		game->texture_pos += game->step;
		color = mlx->texture[game->find_texture].data[game->texture_y
			* mlx->texture[game->find_texture].width + game->texture_x];
		offset = (y * mlx->data.line_length + x * (mlx->data.bits_per_pixel
					/ 8));
		*(unsigned int *)(mlx->data.addr + offset) = color;
		y++;
	}
}
