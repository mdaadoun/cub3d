/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:30:17 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/25 15:05:09 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

//==========
// Libraries
//==========

# include "../mlibx/mlx.h"
# include "../mlibx/mlx_int.h"
# include "libft.h"
# include <math.h>

//==================
// Cub3d global data
//==================

# define WIDTH	320
# define HEIGHT	240
# define RAYS WIDTH

# define GRID 64.0
# define SPEED 0.05
# define ROT_STEP 0.05

# define LOGO "\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ \n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠋⠁⠀⠀⠈⠙⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ \n\
⣿⣿⣿⣿⣿⡿⠟⠋⠁⠀⠀⠀⠀  ⠀⠀⠀⠀⠀ ⠈⠙⠻⢿⣿⣿⣿⣿⣿ \n\
⣿⣿⣿⣏⡁⠀⠀⠀⠀ ⠀  \e[0;31mCub\e[0;33m3\e[m\e[0;31mD\e[m⠀⠀ ⠀⠀⠀⠀⢈⣹⣿⣿⣿ \n\
⣿⣿⡇⠈⠙⠷⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀  ⣀⣤⣴⠾⠋⠁⢸⣿⣿ \n\
⣿⣿⡇⠀⠀⠀⠀⠈⠙⠻⠶⣤⣄⡀⠀⠀⢀⣠⣤⠶⠟⠋⠁⠀⠀⠀⠀⢸⣿⣿ \n\
⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⣷⡞⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿ \n\
⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿ \n\
⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿ \n\
⣿⣿⡇  \e[0;36mmdaadoun\e[m \e[0;34m&&\e[m \e[0;36mdlaidet\e[m   ⢸⣿⣿\n\
⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿ \n\
⣿⣿⣧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⣿⣿ \n\
⣿⣿⣿⣿⣿⣶⣤⣀⠀⠀⠀⠀⠀⠀⣿⡇ ⠀⠀⠀⠀⠀⣀⣤⣶⣿⣿⣿⣿⣿ \n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣤⣀⠀⣿⡇ ⣀⣤⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿ \n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ \n\
"

//=================
// Cub3d structures
//=================

/*
 *	Errors structures and code keys:
 */

# define MSG_NO_ERROR "Cub3d terminated with success."
# define MSG_ERROR_MALLOC "An error with memory allocation occured."
# define MSG_ERROR_PARAMS "The program need the path of \
a map file as a unique parameter."
# define MSG_ERROR_FILE "The file path or name is incorrect."
# define MSG_ERROR_SCREEN "The screen size is incorrect."
# define MSG_ERROR_FORMAT "The file content is not formated correctly."
# define MSG_ERROR_MAP "The map is not formated correctly."
# define MSG_ERROR_IMG "Image path is invalid."

typedef enum e_errkey {
	NO_ERROR,
	ERROR_PARAMS,
	ERROR_FILE,
	ERROR_SCREEN,
	ERROR_FORMAT,
	ERROR_MAP,
	ERROR_MALLOC,
	ERROR_IMG
}			t_errkey;

/*
 *	World structure:
 */

typedef struct s_buffer
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_buffer;

typedef struct s_color
{
	t_u8	t;
	t_u8	r;
	t_u8	g;
	t_u8	b;
}	t_color;

typedef struct s_image
{
	void		*no;
	t_buffer	*no_buf;
	void		*so;
	t_buffer	*so_buf;
	void		*ea;
	t_buffer	*ea_buf;
	void		*we;
	t_buffer	*we_buf;
}	t_image;

typedef struct s_line
{
	t_u16	x1;
	t_u16	y1;
	t_u16	x2;
	t_u16	y2;
}	t_line;

typedef struct s_rect
{
	t_u16	x;
	t_u16	y;
	t_u16	width;
	t_u16	height;
}	t_rect;

typedef struct s_world {
	bool	update;
	t_color	*flr_color;
	t_rect	*flr_rect;
	t_color	*cel_color;
	t_rect	*cel_rect;
}	t_world;

/*
 *	Player structure:
 */

typedef struct s_player {
	t_u64	map_x;
	t_u64	map_y;
	t_f32	grid_x;
	t_f32	grid_y;
	t_f32	angle;
}	t_player;

/*
 *	Data structure:
 */

typedef struct s_data {
	t_list_str	*filedata;
	char		*filepath;
	char		*imgpath_ea;
	char		*imgpath_no;
	char		*imgpath_so;
	char		*imgpath_we;
	char		*color_f;
	char		*color_c;
}	t_data;

/*
 *	Window structure:
 */

typedef struct s_display {
	void	*mlx;
	void	*win;
	void	*img;
	int		win_x;
	int		win_y;
}	t_display;

/*
 *	Window structure:
 */

typedef struct s_map {
	char	**arr;
	int		x;
	int		y;
}	t_map;

/*
 *	Rays structure:
 */

typedef enum e_texture {
	TEXTURE_NORTH,
	TEXTURE_EAST,
	TEXTURE_SOUTH,
	TEXTURE_WEST,
}			t_texture;

typedef struct s_ray {
	t_texture		texture;
	t_u16			target_x;
	t_u16			target_y;
	t_u16			prev_tgx;
	t_u16			prev_tgy;
	t_u16			column_index;
	t_f32			angle;
	t_f32			length;
}	t_ray;

/*
 *	Rays structure:
 */

typedef struct s_render {
	t_buffer	*bs;
	t_f64		lineheight;
	t_f64		step;
	t_f64		texpos;
	int			drawstart;
	int			drawend;
	char		*img;
	char		*pix;
}	t_render;

/*
 *	Main structure:
 */

typedef struct s_cub {
	t_display	*display;
	t_player	*player;
	t_world		*world;
	t_image		*img;
	t_data		*data;
	t_map		*map;
	t_ray		rays[WIDTH];
	t_f64		fov;
	t_f64		rays_steps;
	t_color		color;
	t_rect		rect;
}	t_cub;

/*
 * Initialization functions
 *		files:
 *			cub_events.c
 */

void		cub_init_events(t_cub *cub);

/*
 * File functions
 *		files:
 *			cub_file.c
 */

void		cub_get_data(t_cub *cub, char **av);

/*
 * Free functions
 *		files:
 *			cub_free.c
 */

void		cub_free_before_exit(t_cub *cub, t_errkey errkey);
void		cub_free_strarr(char **split);

/*
 * Errors functions
 *		files:
 *			cub_errors.c
 */

void		cub_print_error(t_errkey errkey, t_u8 out);

/*
 * Errors functions
 *		files:
 *			cub_utils.c
 */

void		*cub_alloc(t_cub *cub, size_t nmemb, size_t size);
bool		cub_is_player(char c);
void		*cub_get_texture(t_cub *cub, t_texture id);
char		*cub_get_pixel(t_buffer *bs, t_u16 x, t_u16 y);
void		cub_init_player(t_cub *cub, char c, int y, int x);

/*
 * Colors functions
 *		files:
 *			cub_colors.c
 */

void		cub_init_colors(t_cub *cub);

/*
 * Parsing functions
 *		files:
 *			config.c
 *			cub_map.c
 *			cub_check_map.c
 *			cub_check_wall_map.c
 */

t_list_str	*cub_set_config(t_cub *cub);
void		cub_build_map(t_cub *cub, t_list_str *data_list);
void		cub_check_map(t_cub *cub);
void		cub_check_wall_map(t_cub *cub, char **map);
void		cub_check_char_map(t_cub *cub, char **map);
void		cub_map_space_resize(t_cub *cub, char **map);
bool		cub_player_can_go(t_cub *cub, t_f32	x, t_f32 y);

/*
 * Drawing functions
 *		files:
 *			cub_draw.c
 *			cub_draw_helpers.c
 */

void		cub_draw_world(t_cub *cub);
void		cub_draw_rectangle(t_cub *cub, t_rect *rect, t_color *color);
void		cub_draw_pixel(t_buffer *bs, t_u16 x, t_u16 y, t_color *color);

/*
 * Img functions
 * 		files:
 * 			cub_img.c
 */

void		cub_load_img(t_cub *cub);
void		cub_free_img(t_cub *cub);

/*
 * Player functions
 *		files:
 *			cub_player.c
 *			cub_player_move.c
 */

void		cub_move_player(t_cub *cub, t_u16 key);

/*
 * Ray casting functions
 *		files:
 *			cub_rays.c
 */

void		cub_cast_rays(t_cub *cub);

/*
 * Rendering functions
 *		files:
 *			cub_render.c
 */

void		cub_build_render(t_cub *cub);

#endif
