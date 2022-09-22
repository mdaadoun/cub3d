/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 08:17:29 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/22 11:47:38 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	fs_init_window(t_cub *cub)
{
	cub->win = ft_calloc(1, sizeof(t_win));
	cub->win->mlx = mlx_init();
	mlx_get_screen_size(cub->win->mlx, &cub->win->win_x, &cub->win->win_y);
	if (cub->win->win_x < 320 && cub->win->win_y < 240)
		return ;//Error size of screen.
	cub->win->win = mlx_new_window(cub->win->mlx, 320, 240, "Cub3d");
}

void	cub_init(t_cub *cub)
{
	fs_init_window(cub);//Do it at last.
}
