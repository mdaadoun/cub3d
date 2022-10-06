#ifndef CUB_H
# define CUB_H

//==========
// Libraries
//==========

# include "../mlibx/mlx.h"
# include "../mlibx/mlx_int.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>

//======
// Types
//======

typedef signed char			t_i8;
typedef unsigned char		t_u8;
typedef signed short		t_i16;
typedef unsigned short		t_u16;
typedef signed long			t_i32;
typedef unsigned long		t_u32;
typedef float				t_f32;
typedef signed long long	t_i64;
typedef unsigned long long	t_u64;
typedef double				t_f64;

//==================
// Cub3d global data
//==================

# define WIDTH	320
# define HEIGHT	240
# define GRID 64

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

typedef enum e_errkey {
	NO_ERROR,
	ERROR_PARAMS,
	ERROR_FILE,
	ERROR_SCREEN,
	ERROR_FORMAT,
	ERROR_MAP,
	ERROR_MALLOC
}			t_errkey;

/*
 *	Player structure:
 */

typedef struct s_player {
	t_u64	map_x;
	t_u64	map_y;
	t_f32	pos_x;
	t_f32	pos_y;
	t_f32	radiant;
}	t_player;

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

typedef struct s_line
{
	t_u16	x1;
	t_u16	y1;
	t_u16	x2;
	t_u16	y2;
}	t_line;

// typedef struct s_circle
// {
// 	t_u16	x;
// 	t_u16	y;
// 	t_u16	radius;
// }	t_circle;

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

typedef struct s_win {
	void	*mlx;
	void	*win;
	void	*img;
	int		win_x;
	int		win_y;
}	t_win;

/*
 *	Window structure:
 */

typedef struct s_map {
	char	**map;
	int		x;
	int		y;
}	t_map;

/*
 *	Main structure:
 */

typedef struct s_cub {
	t_player	*player;
	t_world		*world;
	t_data		*data;
	t_win		*win;
	t_map		*map;
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

void		cub_get_data(t_cub *cub, int ac, char **av);

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

/*
 * Display functions
 *		files:
 *			cub_display.c
 */

void	cub_init_window(t_cub *cub);
void	cub_init_map(t_cub *cub);

/*
 * Update functions
 *		files:
 *			cub_update.c
 */

int		cub_game_loop(t_cub *cub);

/*
 * Drawing functions
 *		files:
 *			cub_draw.c
 *			cub_draw_helpers.c
 */

void	cub_draw_world(t_cub *cub);
void	cub_draw_rectangle(t_cub *cub, t_rect *rect, t_color *color);
void	cub_draw_line(t_cub *cub, t_line *line, t_color *color);

/*
 * Player functions
 *		files:
 *			cub_player.c
 */

void	cub_move_player(t_cub *cub, t_u16 key);
void	cub_rotate_player(t_cub *cub, t_u16 key);

///////////////////////////////////////////////////////////////////////
// TO DELETE START

# ifndef DEBUG
#  define DEBUG 0
# endif

/*
 *	Debug function:
 *		files:
 */

int			dg_main(t_cub *cub, int ac, char **av);
void		dg_print_arg(int ac, char **av);
void		dg_lst_data(t_cub *cub);

// TO DELETE END
///////////////////////////////////////////////////////////////////////

#endif
