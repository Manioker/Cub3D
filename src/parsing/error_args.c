/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:36:35 by anvacca           #+#    #+#             */
/*   Updated: 2025/03/28 14:11:04 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	error_args(const unsigned int error)
{
	if (error == 1)
		printf(RED"Not enough arguments!\n");
	else if (error == 2)
		printf(RED"Too many arguments!\n");
	else if (error == 3)
		printf(RED"Wrong arguments!\n");
	else if (error == 4)
		printf(RED"File is a directory!\n");
	else if (error == 5)
		printf(RED"File not found!\n");
	return (false);
}
