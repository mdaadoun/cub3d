/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:41:52 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/21 13:28:46 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

//==========
// Libraries
//==========

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

//=================
// Cub3d structures
//=================

/*
 *	Errors structures and keys:
*/

# define MSG_ERROR_MALLOC "An error with memory allocation occured."
# define MSG_ERROR_PARAMS_VALID "The parameters aren't valid."
# define MSG_SUCCESS_EXIT "Cub3d terminated with success."
# define MSG_ERROR_PARAMS "The program need the path of \
a map file as a unique parameter."
# define MSG_ERROR_PATH "The file path is incorrect."
# define MSG_ERROR_CUB "The file is not a .cub file."
# define MSG_ERROR_EMPTY "The map file is empty."
# define MSG_ERROR_WALL "The map need a closed wall."
# define MSG_ERROR_CHAR "The map has wrong chars that can't be parsed."
# define MSG_ERROR_CONTENT "The map missing important chars to be playable."

typedef enum e_err_key {
	NO_ERROR,
	ERROR_PARAMS_NB,
	ERROR_PARAMS_VALID,
	ERROR_MALLOC
}			t_err_key;

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
 *	Main structure:
*/

typedef struct s_cub {
	t_player	player;
	t_data		data;
	char		**map;
}	t_cub;

void	cub_data_set(t_cub *cub, int ac, char **av);
void	cub_exit(char *str);

/*
 *	Debug function:
*/

void	debug_print_arg(int ac, char **av);
void	debug_lst_data(t_cub *cub);

#endif
