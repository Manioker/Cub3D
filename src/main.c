/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:21:39 by anvacca           #+#    #+#             */
/*   Updated: 2025/05/09 11:34:57 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_game	game;

	game.map = NULL;
	if (parser(argc, argv, &game))
	{
		game_loop(&mlx, &game);
		free_game(&game);
	}
	else
		printf("Wrong map\n");
	free_array(game.map);
	return (0);
}
