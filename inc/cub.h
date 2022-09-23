/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:41:52 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/23 15:26:49 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//==========
// Libraries
//==========

# include "../mlibx/mlx.h"
# include "../mlibx/mlx_int.h"
# include "libft.h"
# include <fcntl.h>

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
# define MSG_ERROR_PATH "The file path is incorrect."
# define MSG_ERROR_FILE "The file is not a .cub file."
# define MSG_ERROR_SCREEN "The screen size is incorrect."
# define MSG_ERROR_FORMAT "The file content is not formated correctly."
# define MSG_ERROR_MAP "The map is not formated correctly."

typedef enum e_errkey {
	NO_ERROR,
	ERROR_PARAMS,
	ERROR_FILE,
	ERROR_PATH,
	ERROR_SCREEN,
	ERROR_FORMAT,
	ERROR_MAP,
	ERROR_MALLOC
}			t_errkey;

/*
 *	Player structure:
 */

typedef struct s_player {
	t_u64	x;
	t_u64	y;
}	t_player;

/*
 *	Data structure:
 */

typedef struct s_data {
	t_list_str	*filedata;
	char		*filepath;
	char		*imgpath_EA;
	char		*imgpath_NO;
	char		*imgpath_SO;
	char		*imgpath_WE;
	char		*color_F;
	char		*color_C;
}	t_data;

/*
 *	Window structure:
 */

typedef struct s_win {
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
}	t_win;

/*
 *	Main structure:
 */

typedef struct s_cub {
	t_player	*player;
	t_data		*data;
	t_win		*win;
	char		**map;
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
void		cub_free_split(char **split);

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

/*
 * Parsing functions
 *		files:
 *			cub_parser.c
 *			cub_map.c
 */

void		cub_parse_data(t_cub *cub);
void		cub_build_map(t_cub *cub);

// TO DELETE:

# ifndef DEBUG
#  define DEBUG 0
# endif

/*
 *	Debug function:
 *		files:
 */

int			dg_main(int ac, char **av);
void		dg_print_arg(int ac, char **av);
void		dg_lst_data(t_cub *cub);

#endif
