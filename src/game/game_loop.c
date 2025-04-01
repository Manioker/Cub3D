/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:52:21 by anvacca           #+#    #+#             */
/*   Updated: 2025/04/01 14:32:11 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int cycle(t_main_s *main_s)
{
	scene(main_s->mlx);
	raycasting(main_s->mlx, main_s->game);
	
	mlx_put_image_to_window(main_s->mlx->mlx, main_s->mlx->mlx_win, main_s->mlx->data.img, 0, 0);
	return (0);
}

void init_game(t_game *game)
{
	game->map[0] = "1111111111";
	game->map[1] = "1000000001";
	game->map[2] = "1000000001";
	game->map[3] = "1000000001";
	game->map[4] = "1000011111";
	game->map[5] = "1000011111";
	game->map[6] = "1000000001";
	game->map[7] = "1000000001";
	game->map[8] = "1000000001";
	game->map[9] = "1111111111";
	game->map[10] = NULL;
	game->first_posx = 7;
	game->first_posy = 7;
	game->posx = 7;
	game->posy = 7;
	game->dirx = -1;
	game->diry = 0;
	game->planex = 0;
	game->planey = 0.66;
	game->hit = 0;
}

void game_loop(t_mlx *mlx, t_game *game)
{
	t_main_s	main_s;
	
	main_s.game = game;
	main_s.mlx = mlx;
	init_game(game);
	init_window(mlx);
	init_image(mlx);
	mlx_hook(mlx->mlx_win, 02, (1L<<0), handle_key_press(), &main_s);
	mlx_loop_hook(mlx->mlx, cycle, &main_s);
	mlx_loop(mlx->mlx);
}
