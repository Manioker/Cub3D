/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:36:35 by anvacca           #+#    #+#             */
/*   Updated: 2025/03/31 12:17:34 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	error_args(const unsigned int error)
{
	if (error == 1)
		printf(RED"Not enough arguments!\n"RESET);
	else if (error == 2)
		printf(RED"Too many arguments!\n"RESET);
	else if (error == 3)
		printf(RED"Wrong arguments!\n"RESET);
	else if (error == 4)
		printf(RED"File is a directory!\n"RESET);
	else if (error == 5)
		printf(RED"File not found!\n"RESET);
	return (false);
}
