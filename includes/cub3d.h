/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:23:22 by anvacca           #+#    #+#             */
/*   Updated: 2025/03/31 14:30:28 by anvacca          ###   ########.fr       */
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
# define WINDOW_X 1280
# define WINDOW_Y 720

struct				s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
};

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	struct s_data	data;
}					t_mlx;

typedef struct s_game
{
	char	*map[10];
	int		first_posx;
	int		first_posy;
	float	posx;
	float	posy;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
	int		mapx;
	int		mapy;
	float	sidedistx;
	float	sidedisty;
} t_game;

typedef struct s_main_s
{
	t_game	*game;
	t_mlx	*mlx;
} t_main_s;

// UTILS
int					ft_strlen(char *str);
int					ft_strncmp(char *str1, char *str2, size_t size);

// PARSING
bool				check_args(int argc, char **argv, int *fd);
bool				error_args(const unsigned int error);

// MLX
void				game_loop(t_mlx *mlx, t_game *game);
bool				init_window(t_mlx *mlx);
void				init_image(t_mlx *mlx);
void				scene(t_mlx *mlx);

#endif
