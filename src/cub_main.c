/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:16:31 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/22 15:33:23 by mdaadoun         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_cub	*cub;

//	if (DEBUG)
//		debug_print_arg(ac, av);
	cub = (t_cub *)cub_alloc(NULL, 1, sizeof(t_cub));
	
	cub_data_set(cub, ac, av);
	cub_init(cub);
	// if no error, print logo and Cub3D running
	ft_printf("%s", CUB3D_LOGO);
	
	mlx_hook(cub->win->win, KeyPress, (1L << 0), fs_key_hook, cub);
	mlx_hook(cub->win->win, DestroyNotify, 1L << 17, fs_close, cub);
	mlx_loop(cub->win->mlx);
	return (0);
}
