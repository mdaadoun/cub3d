/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:16:31 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/27 10:13:29 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	fs_init_window(t_cub *cub)
{
	cub->win = (t_win *)cub_alloc(cub, 1, sizeof(t_win));
	cub->win->mlx = mlx_init();
	mlx_get_screen_size(cub->win->mlx, &cub->win->win_x, &cub->win->win_y);
	if (cub->win->win_x < WIDTH && cub->win->win_y < HEIGHT)
		cub_free_before_exit(cub, NO_ERROR);
	cub->win->win = mlx_new_window(cub->win->mlx, WIDTH, HEIGHT, "Cub3d");
}

static void	fs_process_data(t_cub *cub)
{
	t_list_str	*datalst;

	datalst = cub_set_config(cub);
	// check_valid_colors();
	cub_build_map(cub, datalst);
	cub_check_map(cub);
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

	if (DEBUG) /* TO REMOVE */
		dg_main(ac, av);
	cub = (t_cub *)cub_alloc(NULL, 1, sizeof(t_cub));
	// GET FILE DATA
	cub_get_data(cub, ac, av);
	fs_process_data(cub);
	
	// load data (images, colors)
	// free data not used
	
	// INIT GAME (WINDOW, EVENT)
	fs_init_window(cub);
	cub_init_events(cub);

	// RUN GAME
	ft_printf("%s", LOGO);
	mlx_loop(cub->win->mlx);
	return (0);
}
