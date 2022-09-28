/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:11:51 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/28 10:06:49 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	fs_close(t_cub *cub)
{
	cub_free_before_exit(cub, NO_ERROR);
	return (0);
}

static int	fs_key_hook(int keycode, t_cub *cub)
{
	if (keycode == XK_Escape)
		cub_free_before_exit(cub, NO_ERROR);
	else if (keycode == XK_a)
		ft_printf("a");
	else if (keycode == XK_s)
		ft_printf("s");
	else if (keycode == XK_d)
		ft_printf("d");
	else if (keycode == XK_w)
		ft_printf("w");
	else if (keycode == XK_Left)
		ft_printf("LEFT");
	else if (keycode == XK_Right)
		ft_printf("RIGHT");
	return (0);
}

void	cub_init_events(t_cub *cub)
{
	if (cub->win)
	{
		mlx_hook(cub->win->win, KeyPress, (1L << 0), fs_key_hook, cub);
		mlx_hook(cub->win->win, DestroyNotify, 1L << 17, fs_close, cub);
	}
	if (cub->winmap)
	{
		mlx_hook(cub->winmap->win, KeyPress, (1L << 0), fs_key_hook, cub);
		mlx_hook(cub->winmap->win, DestroyNotify, 1L << 17, fs_close, cub);
	}
}
