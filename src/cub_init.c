/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 08:17:29 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/22 12:03:41 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	fs_init_window(t_cub *cub)
{
	cub->win = ft_calloc(1, sizeof(t_win));
	cub->win->mlx = mlx_init();
	mlx_get_screen_size(cub->win->mlx, &cub->win->win_x, &cub->win->win_y);
	if (cub->win->win_x < WIDTH && cub->win->win_y < HEIGHT)
		return ;//Error size of screen.
	cub->win->win = mlx_new_window(cub->win->mlx, WIDTH, HEIGHT, "Cub3d");
}

void	cub_init(t_cub *cub)
{
	fs_init_window(cub);//Do it at last.
}
