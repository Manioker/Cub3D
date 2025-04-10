/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:55:19 by anvacca           #+#    #+#             */
/*   Updated: 2025/04/09 17:27:59 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_so_no(t_mlx *mlx, t_game *game)
{
	mlx->texture[0].img = mlx_xpm_file_to_image(mlx->mlx, game->no_path,
			&mlx->texture[0].width, &mlx->texture[0].height);
	if (!mlx->texture[0].img)
		return (printf(RED "Texture NO \"%s\" not found!\n" RESET,
				game->no_path), false);
	mlx->texture[0].data = (int *)mlx_get_data_addr(mlx->texture[0].img,
			&mlx->texture[0].bits_per_pixel, &mlx->texture[0].line_length,
			&mlx->texture[0].endian);
	mlx->texture[1].img = mlx_xpm_file_to_image(mlx->mlx, game->so_path,
			&mlx->texture[1].width, &mlx->texture[1].height);
	if (!mlx->texture[1].img)
		return (printf(RED "Texture SO \"%s\" not found!\n" RESET,
				game->so_path), false);
	mlx->texture[1].data = (int *)mlx_get_data_addr(mlx->texture[1].img,
			&mlx->texture[1].bits_per_pixel, &mlx->texture[1].line_length,
			&mlx->texture[1].endian);
	return (true);
}

static bool	init_we_ea(t_mlx *mlx, t_game *game)
{
	mlx->texture[2].img = mlx_xpm_file_to_image(mlx->mlx, game->we_path,
			&mlx->texture[2].width, &mlx->texture[2].height);
	if (!mlx->texture[2].img)
		return (printf(RED "Texture WE \"%s\" not found!\n" RESET,
				game->we_path), false);
	mlx->texture[2].data = (int *)mlx_get_data_addr(mlx->texture[2].img,
			&mlx->texture[2].bits_per_pixel, &mlx->texture[2].line_length,
			&mlx->texture[2].endian);
	mlx->texture[3].img = mlx_xpm_file_to_image(mlx->mlx, game->ea_path,
			&mlx->texture[3].width, &mlx->texture[3].height);
	if (!mlx->texture[3].img)
		return (printf(RED "Texture EA \"%s\" not found!\n" RESET,
				game->ea_path), false);
	mlx->texture[3].data = (int *)mlx_get_data_addr(mlx->texture[3].img,
			&mlx->texture[3].bits_per_pixel, &mlx->texture[3].line_length,
			&mlx->texture[3].endian);
	return (true);
}

bool	init_texture(t_mlx *mlx, t_game *game)
{
	if (!init_so_no(mlx, game) || !init_we_ea(mlx, game))
		return (false);
	return (true);
}
