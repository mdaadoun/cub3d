/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:08 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/25 15:05:05 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	fs_process_data(t_cub *cub)
{
	t_list_str	*datalst;

	datalst = cub_set_config(cub);
	cub_init_colors(cub);
	cub_build_map(cub, datalst);
	cub_check_map(cub);
}

static int	fs_game_loop(t_cub *cub)
{
	t_display	*dsp;

	dsp = cub->display;
	if (cub->world->update)
	{
		cub_cast_rays(cub);
		cub_draw_world(cub);
		cub_build_render(cub);
		mlx_put_image_to_window(dsp->mlx, dsp->win, dsp->img, 0, 0);
		cub->world->update = false;
	}
	return (0);
}

static void	fs_init_cub(t_cub **cub)
{
	t_color	**colptr;

	*cub = (t_cub *) cub_alloc(NULL, 1, sizeof(t_cub));
	(*cub)->world = (t_world *)cub_alloc(NULL, 1, sizeof(t_world));
	(*cub)->world->update = true;
	colptr = &(*cub)->world->cel_color;
	*colptr = (t_color *) cub_alloc(NULL, 1, sizeof(t_color));
	colptr = &(*cub)->world->flr_color;
	*colptr = (t_color *)cub_alloc(NULL, 1, sizeof(t_color));
	(*cub)->player = (t_player *) cub_alloc(NULL, 1, sizeof(t_player));
	(*cub)->map = (t_map *) cub_alloc(NULL, 1, sizeof(t_map));
	(*cub)->img = (t_image *) cub_alloc(NULL, 1, sizeof(t_image));
	(*cub)->fov = M_PI / 3;
	(*cub)->rays_steps = (*cub)->fov / RAYS;
}

static void	fs_init_window(t_cub *cub)
{
	t_display	*dsp;

	cub->display = (t_display *) cub_alloc(cub, 1, sizeof(t_display));
	dsp = cub->display;
	dsp->mlx = mlx_init();
	mlx_get_screen_size(dsp->mlx, &dsp->win_x, &dsp->win_y);
	if (dsp->win_x < WIDTH || dsp->win_y < HEIGHT)
		cub_free_before_exit(cub, NO_ERROR);
	dsp->win = mlx_new_window(dsp->mlx, WIDTH, HEIGHT, "Cub3d");
	dsp->img = mlx_new_image(dsp->mlx, WIDTH, HEIGHT);
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

	if (ac != 2)
		cub_free_before_exit(NULL, ERROR_PARAMS);
	fs_init_cub(&cub);
	cub_get_data(cub, av);
	fs_process_data(cub);
	fs_init_window(cub);
	cub_load_img(cub);
	cub_init_events(cub);
	ft_printf("%s", LOGO);
	mlx_loop_hook(cub->display->mlx, (*fs_game_loop), cub);
	mlx_loop(cub->display->mlx);
	return (0);
}
