/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:23:22 by anvacca           #+#    #+#             */
/*   Updated: 2025/04/10 15:45:29 by rothiery         ###   ########.fr       */
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

# define KEY_ESC 65307
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_RIGHT 65363
# define KEY_E 101
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_TAB 9

# define MOVE_SPEED 0.007f

struct					s_texture
{
	void				*img;
	int					*data;
	int					width;
	int					height;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
};

struct					s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
};

typedef struct s_mlx
{
	void				*mlx;
	void				*mlx_win;
	struct s_texture	texture[4];
	struct s_data		data;
}						t_mlx;

typedef struct s_game
{
	char				*map[10];
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	float				step;
	float				texture_pos;
	int					texture_y;
	int					find_texture;
	int					texture_x;
	int					first_posx;
	int					first_posy;
	float				posx;
	float				posy;
	float				dirx;
	float				diry;
	float				planex;
	float				planey;
	float				raydirx;
	float				raydiry;
	int					mapx;
	int					mapy;
	float				sidedistx;
	float				sidedisty;
	float				deltadistx;
	float				deltadisty;
	float				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					lineheigth;
	int					drawstart;
	int					drawend;
	bool				movement[6];
}						t_game;

typedef struct s_main_s
{
	t_game				*game;
	t_mlx				*mlx;
}						t_main_s;

// UTILS
int						ft_strlen(char *str);
int						ft_strcmp(const char *str1, const char *str2);

// PARSING
bool					check_args(int argc, char **argv, int *fd);
bool					error_args(const unsigned int error);
bool					parser(int argc, char **argv);
char					*ft_strdup(char *str);
char					*ft_strjoinfr(char *s1, char *s2);
char					*ft_strchr(char *s, int c);
char					*get_next_line(int fd);

// MLX
void					game_loop(t_mlx *mlx, t_game *game);
bool					init_window(t_mlx *mlx);
void					init_image(t_mlx *mlx);
void					scene(t_mlx *mlx);
int						handle_key_press(int keycode, t_main_s *main_s);
int						handle_key_release(int keycode, t_game *game);
void					movements(t_game *game);
void					raycasting(t_mlx *mlx, t_game *game);
int						end_game(t_main_s *main_s);
void					display_wall(t_mlx *mlx, t_game *game, unsigned int x);
bool					init_texture(t_mlx *mlx, t_game *game);

#endif
