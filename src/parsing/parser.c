/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:25:47 by anvacca           #+#    #+#             */
/*   Updated: 2025/04/14 12:59:49 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parser(int argc, char **argv, t_game *game)
{
	int	fd;

	if (!check_args(argc, argv, &fd))
		return (false);
	printf("args OK\n");
	if (!parse_walls(fd, game))
		return (false);
	printf("walls ok\n");
	if (!parse_map(fd, game))
		return (false);
	printf("map ok\n");
	return (true);
}
