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
	// (void) data;
	// ft_putstr_fd("\nDatas after parsing:\n", 1);
	ft_printf("imgpath_EA: %s\n", data->imgpath_ea);
	ft_printf("imgpath_NO: %s\n", data->imgpath_no);
	ft_printf("imgpath_SO: %s\n", data->imgpath_so);
	ft_printf("imgpath_WE: %s\n", data->imgpath_we);
	// ft_printf("color_C: %s\n", data->color_c);
	// ft_printf("color_F: %s\n", data->color_f);
}

void	dg_print_map(t_cub *cub)
{
	int	i;

	i = 0;
	ft_printf("\nMap builder\n");
	while (cub->map->map[i])
	{
		ft_printf("%s\e[0;31m$\e[m\n", cub->map->map[i]);
		i++;
	}
}

void	dg_print_colors(t_cub *cub)
{
	t_world	*world;

	cub_init_colors(cub);
	world = cub->world;
	ft_printf("Floor color:\n");
	ft_printf("R:%d, ", world->flr_color->r);
	ft_printf("G:%d, ", world->flr_color->g);
	ft_printf("B:%d\n", world->flr_color->b);
	ft_printf("Celling color:\n");
	ft_printf("R:%d, ", world->cel_color->r);
	ft_printf("G:%d, ", world->cel_color->g);
	ft_printf("B:%d\n", world->cel_color->b);
}

int	dg_main(t_cub *cub, int ac, char **av)
{
	t_list_str	*datalst;

	// ft_printf("debug on.\n");
	// dg_print_arg(ac, av);
	cub_get_data(cub, ac, av);
	// dg_print_data_before(cub);
	datalst = cub_set_config(cub);
	dg_print_data_after(cub);
	dg_print_colors(cub);
	cub_build_map(cub, datalst);
	cub_check_map(cub);
	dg_print_map(cub);
	cub_init_map(cub);
	// cub_init_window(cub);
	cub_init_events(cub);
	mlx_loop_hook(cub->win->mlx, (*cub_game_loop), cub);
	mlx_loop(cub->win->mlx);
	cub_free_before_exit(cub, NO_ERROR);
	return (0);
}
