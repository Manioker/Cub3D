/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:38:28 by anvacca           #+#    #+#             */
/*   Updated: 2025/04/09 12:02:43 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_game(t_main_s *main_s)
{
	if (main_s->mlx->mlx_win)
		mlx_destroy_window(main_s->mlx->mlx, main_s->mlx->mlx_win);
	if (main_s->mlx->data.img)
		mlx_destroy_image(main_s->mlx->mlx, main_s->mlx->data.img);
	//free
	exit(0);
}
