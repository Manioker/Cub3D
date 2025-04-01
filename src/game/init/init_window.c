/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:53:13 by anvacca           #+#    #+#             */
/*   Updated: 2025/03/31 13:02:41 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"

bool	init_window(t_mlx *mlx)
{
 	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		printf(RED"ERROR: failed to init mlx\n"RESET);
		return (false);
	}
 	mlx->mlx_win = mlx_new_window(mlx->mlx, WINDOW_X, WINDOW_Y, "Cub3D");
	if (!mlx->mlx_win)
	{
		printf(RED"ERROR: failed to init mlx\n"RESET);
		return (false);
	}
	return (true);
}
