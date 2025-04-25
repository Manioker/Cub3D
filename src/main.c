/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:21:39 by anvacca           #+#    #+#             */
/*   Updated: 2025/04/25 10:53:41 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_game	game;

	if (parser(argc, argv, &game))
		game_loop(&mlx, &game);
	free_game(&game);
	return (0);
}
