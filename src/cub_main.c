/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:16:31 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/27 16:34:56 by mdaadoun         ###   ########.fr       */
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
	char		*colc;
	char		*colf;

	datalst = cub_set_config(cub);
	colc = cub->data->color_c;
	colf = cub->data->color_f;
	if (!cub_check_set_colors(cub, cub->world->celling_color, colc))
		cub_free_before_exit(cub, ERROR_FORMAT);
	if (!cub_check_set_colors(cub, cub->world->floor_color, colf))
		cub_free_before_exit(cub, ERROR_FORMAT);
	cub_build_map(cub, datalst);
	cub_check_map(cub);
	(void) colc;
	(void) colf;
}

static void	fs_init_cub(t_cub **cub)
{
	t_color	**colptr;

	*cub = (t_cub *)cub_alloc(NULL, 1, sizeof(t_cub));
	(*cub)->world = (t_world *)cub_alloc(NULL, 1, sizeof(t_world));
	colptr = &(*cub)->world->celling_color;
	*colptr = (t_color *)cub_alloc(NULL, 1, sizeof(t_color));
	colptr = &(*cub)->world->floor_color;
	*colptr = (t_color *)cub_alloc(NULL, 1, sizeof(t_color));
	(*cub)->player = (t_player *)cub_alloc(NULL, 1, sizeof(t_player));
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
	fs_init_window(cub);
	cub_init_events(cub);
	ft_printf("%s", LOGO);
	mlx_loop(cub->win->mlx);
	return (0);
}
