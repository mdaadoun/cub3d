/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 08:17:29 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/22 08:30:39 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	fs_init_window(t_win *win)
{
	win->mlx = mlx_init();
	mlx_get_screen_size(win->mlx, &win->win_x, &win->win_y);
	if (win->win_x < 320 && win->win_y < 240)
		return ;//Error size of screen.
	win->win = mlx_new_window(win->mlx, 320, 240, "Cub3d");
}

void	cub_init(t_cub *cub)
{
	fs_init_window(&cub->win);//Do it at last.
}
