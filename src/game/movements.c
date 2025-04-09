/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:56:14 by anvacca           #+#    #+#             */
/*   Updated: 2025/04/09 12:07:07 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move(t_game *game, int key, float speed)
{
	if (key == KEY_W)
	{
		if (game->map[(int)game->posy][(int)(game->posx + game->dirx
				* speed)] != '1')
			game->posx += game->dirx * speed;
		if (game->map[(int)(game->posy + game->diry
				* speed)][(int)game->posx] != '1')
			game->posy += game->diry * speed;
	}
	if (key == KEY_S)
	{
		if (game->map[(int)game->posy][(int)(game->posx - game->dirx
				* speed)] != '1')
			game->posx -= game->dirx * speed;
		if (game->map[(int)(game->posy - game->diry
				* speed)][(int)game->posx] != '1')
			game->posy -= game->diry * speed;
	}
}

static void	rotate(t_game *game, float speed)
{
	const float	old_dirx = game->dirx;
	const float	old_planex = game->planex;

	game->dirx = game->dirx * cos(speed) - game->diry * sin(speed);
	game->diry = old_dirx * sin(speed) + game->diry * cos(speed);
	game->planex = game->planex * cos(speed) - game->planey * sin(speed);
	game->planey = old_planex * sin(speed) + game->planey * cos(speed);
}

static void	side_move(t_game *game, int key, float speed)
{
	if (key == KEY_A)
	{
		if (game->map[(int)game->posy][(int)(game->posx - game->planex
				* speed)] != '1')
			game->posx -= game->planex * speed;
		if (game->map[(int)(game->posy - game->planey
				* speed)][(int)game->posx] != '1')
			game->posy -= game->planey * speed;
	}
	else if (key == KEY_D)
	{
		if (game->map[(int)game->posy][(int)(game->posx + game->planex
				* speed)] != '1')
			game->posx += game->planex * speed;
		if (game->map[(int)(game->posy + game->planey
				* speed)][(int)game->posx] != '1')
			game->posy += game->planey * speed;
	}
}

void	movements(t_game *game)
{
	if (game->movement[0] == true)
		move(game, KEY_W, MOVE_SPEED);
	if (game->movement[1] == true)
		move(game, KEY_S, MOVE_SPEED);
	if (game->movement[2])
		side_move(game, KEY_A, MOVE_SPEED);
	if (game->movement[3])
		side_move(game, KEY_D, MOVE_SPEED);
	if (game->movement[4] == true)
		rotate(game, MOVE_SPEED);
	if (game->movement[5] == true)
		rotate(game, -MOVE_SPEED);
}
