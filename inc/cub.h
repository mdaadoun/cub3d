
#ifndef CUB3D_H
# define CUB3D_H

//==========
// Libraries
//==========

# include "libft.h"

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
# define MSG_ERROR_PARAMS_NB "Philosophers needs 4 parameters (+ 1 optional)."
# define MSG_ERROR_PARAMS_VALID "The parameters aren't valid."
# define MSG_ERROR_THREAD_CREATE "An error when creating a thread occured."
# define MSG_ERROR_THREAD_JOIN "An error when joining a thread occured."
# define MSG_ERROR_MALLOC "An error with memory allocation occured."
# define MSG_ERROR_PARAMS_NB "Philosophers needs 4 parameters (+ 1 optional)."
# define MSG_ERROR_PARAMS_VALID "The parameters aren't valid."
# define MSG_ERROR_THREAD_CREATE "An error when creating a thread occured."
# define MSG_ERROR_THREAD_JOIN "An error when joining a thread occured."
# define MSG_SUCCESS_EXIT "So long and thanks for all the honey."
# define MSG_ERROR_PARAMS "Error\nThe program need the path of \
a map file as a unique parameter."
# define MSG_ERROR_PATH "Error\nThe file path is incorrect."
# define MSG_ERROR_BER "Error\nThe file is not a ber file."
# define MSG_ERROR_MALLOC "Error\nThe memory allocation failed."
# define MSG_ERROR_EMPTY "Error\nThe map file is empty."
# define MSG_ERROR_RECTANGLE "Error\nThe map is not a rectangle."
# define MSG_ERROR_WALL "Error\nThe map need a closed wall."
# define MSG_ERROR_CHAR "Error\nThe map has wrong chars that can't be parsed."
# define MSG_ERROR_CONTENT "Error\nThe map missing important chars \
to be playable."

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
}	t_player;

/*
 *	Data structure:
*/

typedef struct s_data {
}	t_data;

/*
 *	Main structure:
*/

typedef struct s_cub {
}	t_cub;

#endif
