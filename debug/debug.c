/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:52:32 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/27 08:49:27 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	dg_print_arg(int ac, char **av)
{
	int		i;

	i = 0;
	ft_printf("Number of argument: %d\n", ac);
	while (i < ac)
	{
		ft_printf("Argument %d: %s\n", i, av[i]);
		i++;
	}
}

void	dg_print_data_before(t_cub *cub)
{
	t_list_str	*data;

	data = cub->data->filedata;
	ft_putstr_fd("\nData List from file\n", 1);
	while (data)
	{
		ft_putstr_fd(data->str, 1);
		data = data->next;
	}
}

void	dg_print_data_after(t_cub *cub)
{
	t_data	*data;

	data = cub->data;
	(void) data;
	ft_putstr_fd("\nDatas after parsing:\n", 1);
	ft_printf("imgpath_EA: %s\n", data->imgpath_ea);
	ft_printf("imgpath_NO: %s\n", data->imgpath_no);
	ft_printf("imgpath_SO: %s\n", data->imgpath_so);
	ft_printf("imgpath_WE: %s\n", data->imgpath_we);
	ft_printf("color_C: %s\n", data->color_c);
	ft_printf("color_F: %s\n", data->color_f);
}

void	dg_print_map(t_cub *cub)
{
	int	i;

	i = 0;
	ft_printf("\nMap builder\n");
	while (cub->map[i])
	{
		ft_printf("%s\n", cub->map[i]);
		i++;
	}
}

int	dg_main(int ac, char **av)
{
	t_cub	*cub;

	ft_printf("debug on.\n");
	dg_print_arg(ac, av);
	cub = (t_cub *)cub_alloc(NULL, 1, sizeof(t_cub));
	cub_get_data(cub, ac, av);
	dg_print_data_before(cub);
	cub_set_config(cub);
	// check_valid_colors();
	cub_build_map(cub, cub->data->filedata);
	dg_print_data_after(cub);
	dg_print_map(cub);
	cub_free_before_exit(cub, NO_ERROR);
	return (0);
}
