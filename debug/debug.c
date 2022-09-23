/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:52:32 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/23 10:52:59 by mdaadoun         ###   ########.fr       */
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

	data = cub->data->data_list;
	ft_putstr_fd("\nData List\n", 1);
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
	ft_putstr_fd("\nDatas:\n", 1);
}

int dg_main(int ac, char **av)
{
	t_cub	*cub;

	ft_printf("debug on.\n");
	dg_print_arg(ac, av);
	cub = (t_cub *)cub_alloc(NULL, 1, sizeof(t_cub));
	cub_get_data(cub, ac, av);
	dg_print_data_before(cub);
	cub_parse_data(cub);
	dg_print_data_after(cub);
	cub_free_before_exit(cub, NO_ERROR);
	return (0);
}
