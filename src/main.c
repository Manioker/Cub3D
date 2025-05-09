/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:21:39 by anvacca           #+#    #+#             */
/*   Updated: 2025/05/09 13:35:07 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_game	game;

	game.map = NULL;
	game.so_path = NULL;
	game.no_path = NULL;
	game.we_path = NULL;
	game.ea_path = NULL;
	if (parser(argc, argv, &game))
		game_loop(&mlx, &game);
	else
		printf("Wrong map\n");
	free_game(&game);
	return (0);
}
