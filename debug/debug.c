/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:52:32 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/22 13:05:21 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

// void	debug_print_arg(int ac, char **av)
// {
// 	int		i;

// 	i = 0;
// 	ft_printf("Number of argument: %d\n", ac);
// 	while (i < ac)
// 	{
// 		ft_printf("Argument %d: %s\n", i, av[i]);
// 		i++;
// 	}
// }

// void	debug_lst_data(t_cub *cub)
// {
// 	t_list_str	*data;

// 	data = cub->data.data_list;
// 	ft_putstr_fd("\nData List\n", 1);
// 	while (data)
// 	{
// 		ft_putstr_fd(data->str, 1);
// 		data = data->next;
// 	}
// }

int start_debug()
{
	ft_printf("debug on.\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = ft_calloc(1, sizeof(t_cub));
//	if (DEBUG)
//		debug_print_arg(ac, av);
	ft_printf("Cub3D running...\n");
	cub_data_set(cub, ac, av);
	cub_init(cub);
	mlx_hook(cub->win->win, KeyPress, (1L << 0), fs_key_hook, cub);
	mlx_hook(cub->win->win, DestroyNotify, 1L << 17, fs_close, cub);
	mlx_loop(cub->win->mlx);
	return (0);
}
