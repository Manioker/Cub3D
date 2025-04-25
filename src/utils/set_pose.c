/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:54:13 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/25 11:56:52 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pose(t_game *game, bool *player_def, unsigned int y,
		unsigned int x)
{
	game->posx = x;
	game->posy = y;
	*player_def = true;
}
