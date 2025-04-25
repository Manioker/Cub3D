/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:50:45 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/25 12:51:50 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	no_player(bool player)
{
	if (!player)
		return (printf("no player\n"), false);
	return (true);
}
