/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:16:31 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/21 15:37:09 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

// void	cub_initialize_cub3D(t_cub **cub)
// {

// }

int	main(int ac, char **av)
{
	t_cub	cub;

	// if (DEBUG)
	// 	debug_print_arg(ac, av);
	ft_printf("Cub3D running...\n");
	// cub_initialize_cub3D(cub);
	cub_data_set(&cub, ac, av);
	cub_free_before_exit(&cub, NO_ERROR);
	return (0);
}
