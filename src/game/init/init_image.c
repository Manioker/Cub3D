/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:25 by anvacca           #+#    #+#             */
/*   Updated: 2025/03/31 13:09:30 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image(t_mlx *mlx)
{
	mlx->data.img = mlx_new_image(mlx->mlx, WINDOW_X, WINDOW_Y);
	mlx->data.addr = mlx_get_data_addr(mlx->data.img,
			&mlx->data.bits_per_pixel, 
			&mlx->data.line_length,
			&mlx->data.endian);
}
