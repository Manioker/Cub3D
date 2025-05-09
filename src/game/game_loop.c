/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:52:21 by anvacca           #+#    #+#             */
/*   Updated: 2025/05/09 13:12:16 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int cycle(t_main_s *main_s)
{
	movements(main_s->game);
	scene(main_s->mlx, main_s->game);
	raycasting(main_s->mlx, main_s->game);
	mlx_put_image_to_window(main_s->mlx->mlx, main_s->mlx->mlx_win, main_s->mlx->data.img, 0, 0);
	return (0);
}

static void	init_player_ns(t_game *game)
{
	if (game->p_orient == 'S')
	{
		game->dirx = 0;
		game->diry = 1;  // South direction, going down
		game->planex = -0.66;
		game->planey = 0;
	}
	else if (game->p_orient == 'N')
	{
		game->dirx = 0;
		game->diry = -1;  // North direction, going up
		game->planex = 0.66;
		game->planey = 0;
	}
}

static void	init_player_ew(t_game *game)
{
	if (game->p_orient == 'E')
	{
		game->dirx = 1;  // East direction, right
		game->diry = 0;
		game->planex = 0;
		game->planey = 0.66;  // Camera plane to simulate FOV
	}
	else if (game->p_orient == 'W')
	{
		game->dirx = -1;  // West direction, left
		game->diry = 0;
		game->planex = 0;
		game->planey = -0.66;  // Camera plane to simulate FOV
	}
}

void init_game(t_game *game)
{
	init_player_ns(game);
	init_player_ew(game);
	game->hit = 0;
	game->movement[0] = false;
	game->movement[1] = false;
	game->movement[2] = false;
	game->movement[3] = false;
	game->movement[4] = false;
	game->movement[5] = false;
}

void game_loop(t_mlx *mlx, t_game *game)
{
	t_main_s	main_s;

	main_s.game = game;
	main_s.mlx = mlx;
	init_game(game);
	init_window(mlx);
	if (!init_texture(mlx, game))
		end_game(&main_s);
	init_image(mlx);
	mlx_hook(mlx->mlx_win, 02, (1L<<0), handle_key_press, &main_s);
	mlx_hook(mlx->mlx_win, 03, (1L<<1), handle_key_release, game);
	mlx_loop_hook(mlx->mlx, cycle, &main_s);
	mlx_hook(mlx->mlx_win, 17, 0L, end_game, &main_s);
	mlx_loop(mlx->mlx);
}
