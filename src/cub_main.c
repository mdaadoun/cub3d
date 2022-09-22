/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:16:31 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/22 09:38:21 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

// void	cub_initialize_cub3D(t_cub **cub)
// {

// }

int	fs_close(t_cub *cub)
{
	cub_free_before_exit(cub, NO_ERROR);
	return (0);
}

int	fs_key_hook(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		cub_free_before_exit(cub, NO_ERROR);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	// if (DEBUG)
	// 	debug_print_arg(ac, av);
	ft_printf("Cub3D running...\n");
//	cub_data_set(&cub, ac, av);
	cub_init(&cub);
	mlx_key_hook(cub.win.win, fs_key_hook, &cub);
	mlx_hook(cub.win.win, DestroyNotify, 1L << 17, fs_close, &cub);
	mlx_loop(cub.win.mlx);
	cub_free_before_exit(&cub, NO_ERROR);
	(void)ac;
	(void)av;
	return (0);
}
