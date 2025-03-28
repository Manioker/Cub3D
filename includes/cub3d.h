/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:23:22 by anvacca           #+#    #+#             */
/*   Updated: 2025/03/28 14:40:10 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>			// open
# include <unistd.h>		// close, read, write
# include <stdio.h>			// printf, perror
# include <stdlib.h>		// malloc, free
# include <string.h>		// strerror, exit
# include <stdbool.h>		// Booleans
# include <math.h>

#define RED			"\e[38;5;196m"

// PARSING
bool	check_args(int argc, char **argv, int *fd);
bool	error_args(const unsigned int error);

//UTILS
int	ft_strlen(char *str);
int	ft_strcmp(const char *str1, const char *str2);

#endif
