/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:33:58 by anvacca           #+#    #+#             */
/*   Updated: 2025/04/04 12:50:14 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->movement[0] = true;
	if (keycode == KEY_S)
		game->movement[1] = true;
	if (keycode == KEY_A)
		game->movement[2] = true;
	if (keycode == KEY_D)
		game->movement[3] = true;
	if (keycode == KEY_ARROW_LEFT)
		game->movement[4] = true;
	if (keycode == KEY_ARROW_RIGHT)
		game->movement[5] = true;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->movement[0] = false;
	if (keycode == KEY_S)
		game->movement[1] = false;
	if (keycode == KEY_A)
		game->movement[2] = false;
	if (keycode == KEY_D)
		game->movement[3] = false;
	if (keycode == KEY_ARROW_LEFT)
		game->movement[4] = false;
	if (keycode == KEY_ARROW_RIGHT)
		game->movement[5] = false;
	return (0);
}
