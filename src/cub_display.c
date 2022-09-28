/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:16:31 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/28 10:10:53 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	cub_init_window(t_cub *cub)
{
	cub->win = (t_win *)cub_alloc(cub, 1, sizeof(t_win));
	cub->win->mlx = mlx_init();
	mlx_get_screen_size(cub->win->mlx, &cub->win->win_x, &cub->win->win_y);
	if (cub->win->win_x < WIDTH || cub->win->win_y < HEIGHT)
		cub_free_before_exit(cub, NO_ERROR);
	cub->win->win = mlx_new_window(cub->win->mlx, WIDTH, HEIGHT, "Cub3d");
}

static void	fs_get_map_size(t_cub *cub)
{
	cub->map->y = ft_strlen(cub->map->map[0]);
	cub->map->x = ft_count_tab_string(cub->map->map);
}

void	cub_init_map(t_cub *cub)
{
	fs_get_map_size(cub);
	cub->winmap = (t_win *)cub_alloc(cub, 1, sizeof(t_win));
	cub->winmap->mlx = mlx_init();
	mlx_get_screen_size(cub->winmap->mlx, &cub->winmap->win_x,
		&cub->winmap->win_y);
	if (cub->winmap->win_x < cub->map->x * GRID
		|| cub->winmap->win_y < cub->map->y * GRID)
	{
		ft_putstr_fd("incorrect size\n", 1);
		cub_free_before_exit(cub, NO_ERROR);
	}
	cub->winmap->win = mlx_new_window(cub->winmap->mlx, cub->map->y * GRID, cub->map->x * GRID, "Cub3d	Minimap");
}
