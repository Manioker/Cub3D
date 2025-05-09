/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:54:13 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/09 12:15:27 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pose(t_game *game, bool *player_def, unsigned int y,
		unsigned int x)
{
	game->posx = x;
	game->posy = y;
	*player_def = true;
	game->p_orient = game->map[y][x];
}
