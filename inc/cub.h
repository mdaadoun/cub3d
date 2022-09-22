/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:41:52 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/22 18:10:50 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

//==========
// Libraries
//==========

# include "../mlbx/mlx.h"
# include "../mlbx/mlx_int.h"
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

# define CUB3D_LOGO "\
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
 *	Errors structures and keys:
*/

# define MSG_ERROR_MALLOC "An error with memory allocation occured."
# define MSG_SUCCESS_EXIT "Cub3d terminated with success."
# define MSG_ERROR_PARAMS "The program need the path of \
a map file as a unique parameter."
# define MSG_ERROR_PATH "The file path is incorrect."
# define MSG_ERROR_FILE_EXT "The file is not a .cub file."
# define MSG_ERROR_FILE_MISSING "The path for the file is not correct."
# define MSG_ERROR_EMPTY "The map file is empty."
# define MSG_ERROR_WALL "The map need a closed wall."
# define MSG_ERROR_CHAR "The map has wrong chars that can't be parsed."
# define MSG_ERROR_CONTENT "The map missing important chars to be playable."

typedef enum e_errkey {
	NO_ERROR,
	ERROR_PARAMS,
	ERROR_FILE_EXT,
	ERROR_FILE_MISSING,
	ERROR_PARAMS_VALID,
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
	t_list_str	*data_list;
	char		*data_file;
}	t_data;

/*
 *	Player structure:
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

void		cub_data_set(t_cub *cub, int ac, char **av);
void		cub_exit(char *str);
void		cub_init(t_cub *cub);

/*
 * Free functions
 *		files:
 *			cub_free.c
*/

void		cub_free_before_exit(t_cub *cub, t_errkey errkey);

/*
 * Errors functions
 *		files:
 *			cub_errors.c
*/

void		cub_print_error(t_errkey errkey, t_u8 out);
char		*cub_get_error_msg(t_errkey errkey);
int			cub_get_error_length(t_errkey errkey);

/*
 * Errors functions
 *		files:
 *			cub_utils.c
*/

void *cub_alloc(t_cub *cub, size_t nmemb, size_t size);

# ifndef DEBUG
#  define DEBUG 1
# endif

/*
 *	Debug function:
*/

int		dg_main(int ac, char **av);
void	dg_print_arg(int ac, char **av);
void	dg_lst_data(t_cub *cub);

#endif
