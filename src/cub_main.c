#include "../inc/cub.h"

static void	fs_process_data(t_cub *cub)
{
	t_list_str	*datalst;

	datalst = cub_set_config(cub);
	cub_init_colors(cub);
	cub_build_map(cub, datalst);
	cub_check_map(cub);
}

static void	fs_init_cub(t_cub **cub)
{
	t_color	**colptr;

	*cub = (t_cub *)cub_alloc(NULL, 1, sizeof(t_cub));
	(*cub)->world = (t_world *)cub_alloc(NULL, 1, sizeof(t_world));
	(*cub)->world->update = true;
	colptr = &(*cub)->world->cel_color;
	*colptr = (t_color *)cub_alloc(NULL, 1, sizeof(t_color));
	colptr = &(*cub)->world->flr_color;
	*colptr = (t_color *)cub_alloc(NULL, 1, sizeof(t_color));
	(*cub)->player = (t_player *)cub_alloc(NULL, 1, sizeof(t_player));
	(*cub)->map = (t_map *)cub_alloc(NULL, 1, sizeof(t_map));
}

/*
 *	CUBE3D
 *	======
 *		1. Initialize the main structure.
 *		2. Get data from the map file.
 * 		3. Set config and build map.
 * 		4. Load resources, init window and set events.
 * 		5. Start game engine.
 */
int	main(int ac, char **av)
{
	t_cub	*cub;

	fs_init_cub(&cub);
	if (DEBUG) /* TO REMOVE */
		dg_main(cub, ac, av);
	cub_get_data(cub, ac, av);
	fs_process_data(cub);
	cub_init_window(cub);
	// cub_init_map(cub);
	cub_init_events(cub);
	ft_printf("%s", LOGO);
	mlx_loop_hook(cub->win->mlx, (*cub_game_loop), cub);
	mlx_loop(cub->win->mlx);
	return (0);
}
