#include "../inc/cub.h"

static void	fs_get_map_size(t_cub *cub)
{
	cub->map->x = ft_strlen(cub->map->arr[0]);
	cub->map->y = ft_count_tab_string(cub->map->arr);
}

void	cub_init_map(t_cub *cub)
{
	fs_get_map_size(cub);
	cub->display = (t_display *)cub_alloc(cub, 1, sizeof(t_display));
	cub->display->mlx = mlx_init();
	mlx_get_screen_size(cub->display->mlx, &cub->display->win_x,
		&cub->display->win_y);
	if (cub->display->win_x < cub->map->x * GRID
		|| cub->display->win_y < cub->map->y * GRID)
		cub_free_before_exit(cub, ERROR_MAP);
	cub->display->win = mlx_new_window(cub->display->mlx, cub->map->x * GRID, cub->map->y * GRID, "Cub3d	Minimap");
	cub->display->img = mlx_new_image(cub->display->mlx, cub->map->x * GRID, cub->map->y * GRID);
}

static void	fs_get_rect(t_cub *cub, int x, int y, char c)
{
	t_rect	*rect;

	rect = &cub->rect;
	if (cub_is_player(c))
	{
		rect->height = 8;
		rect->width = 8;
		rect->x = ((cub->player->map_x + cub->player->grid_x) * GRID) - 4;
		rect->y = ((cub->player->map_y + cub->player->grid_y) * GRID) - 4;
	}
	else
	{
		rect->height = GRID;
		rect->width = GRID;
		rect->x = x * GRID;
		rect->y = y * GRID;
	}
}

static void	fs_get_color(t_cub *cub, char c)
{
	t_color	*color;

	color = &cub->color;
	if (c == '1')
	{
		color->b = 150;
		color->r = 20;
		color->g = 65;
	}
	if (c == '0')
	{
		color->b = 200;
		color->r = 200;
		color->g = 200;
	}
	if (cub_is_player(c))
	{
		color->b = 0;
		color->r = 150;
		color->g = 0;
	}
	color->t = 0;
}

void	dg_draw_map(t_cub *cub, char **map)
{
	int		x;
	int		y;
	t_color colbg;
	t_rect	recbg;

	x = 0;
	y = 0;
	colbg.b = 0;
	colbg.g = 0;
	colbg.r = 0;
	colbg.t = 0;
	recbg.x = 0;
	recbg.y = 0;
	recbg.width = cub->map->x * GRID;
	recbg.height = cub->map->y * GRID;
	cub_draw_rectangle(cub, &recbg, &colbg);
	while (map[y] && map[y][x])
	{
		if (cub_is_player(map[y][x]))
		{
			fs_get_color(cub, '0');
			fs_get_rect(cub, x, y, '0');
			cub_draw_rectangle(cub, &cub->rect, &cub->color);
		}
		fs_get_color(cub, map[y][x]);
		fs_get_rect(cub, x, y, map[y][x]);
		if (map[y][x] != ' ')
			cub_draw_rectangle(cub, &cub->rect, &cub->color);
		x++;
		if (!map[y][x])
		{
			x = 0;
			y++;
		}
	}
	cub->world->update = true;
}

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
	while (cub->map->arr[i])
	{
		ft_printf("%s\e[0;31m$\e[m\n", cub->map->arr[i]);
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
	cub_load_img(cub);
	// cub_init_window(cub);
	cub_init_events(cub);
	mlx_loop_hook(cub->display->mlx, (*dg_game_loop), cub);
	mlx_loop(cub->display->mlx);
	cub_free_before_exit(cub, NO_ERROR);
	return (0);
}
