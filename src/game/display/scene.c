/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:09:09 by anvacca           #+#    #+#             */
/*   Updated: 2025/05/09 11:47:58 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	scene(t_mlx *mlx, t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < WINDOW_Y / 2)
	{
		x = 0;
		while (x < WINDOW_X)
		{
			*(unsigned int *)(mlx->data.addr + (y * mlx->data.line_length + x
					* (mlx->data.bits_per_pixel / 8))) = game->c_color;
			x++;
		}
		y++;
	}
	while (y < WINDOW_Y)
	{
		x = 0;
		while (x < WINDOW_X)
		{
			*(unsigned int *)(mlx->data.addr + (y * mlx->data.line_length + x
					* (mlx->data.bits_per_pixel / 8))) = game->f_color;
			x++;
		}
		y++;
	}
}
