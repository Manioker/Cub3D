/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:54:13 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/14 13:05:49 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pose(t_game *game, bool *player_def, unsigned int i,
		unsigned int i2)
{
	game->first_posx = i2;
	game->first_posy = i;
	*player_def = 1;
}
