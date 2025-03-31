/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:23:22 by anvacca           #+#    #+#             */
/*   Updated: 2025/03/31 12:01:20 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"

# include <fcntl.h> // open
# include <math.h>
# include <stdbool.h> // Booleans
# include <stdio.h>   // printf, perror
# include <stdlib.h>  // malloc, free
# include <string.h>  // strerror, exit
# include <unistd.h>  // close, read, write

# define RED "\e[38;5;196m"
# define RESET "\e[0m"

// MLX
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

// PARSING
bool		check_args(int argc, char **argv, int *fd);
bool		error_args(const unsigned int error);

// UTILS
int			ft_strlen(char *str);
int			ft_strncmp(char *str1, char *str2, size_t size);

#endif
