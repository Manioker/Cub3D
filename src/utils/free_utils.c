/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:05:35 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/09 12:32:32 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **arr)
{
	unsigned int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_game(t_game *game)
{
	free_array(game->map);
	if (game && game->we_path)
		free(game->we_path);
	if (game && game->ea_path)
		free(game->ea_path);
	if (game && game->no_path)
		free(game->no_path);
	if (game && game->so_path)
		free(game->so_path);
}
