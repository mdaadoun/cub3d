#ifndef DEBUG_H
# define DEBUG 0

//==========
// Libraries
//==========

# include "cub.h"

//==========
// Function
//==========

int		dg_main(t_cub *cub, int ac, char **av);
void	dg_print_arg(int ac, char **av);
void	dg_lst_data(t_cub *cub);
int		dg_game_loop(t_cub *cub);
void	dg_draw_map(t_cub *cub, char **map);
void	dg_build_render(t_cub *cub);

#endif
