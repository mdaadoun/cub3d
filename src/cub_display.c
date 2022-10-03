#include "../inc/cub.h"

void	cub_init_window(t_cub *cub)
{
	cub->win = (t_win *)cub_alloc(cub, 1, sizeof(t_win));
	cub->win->mlx = mlx_init();
	mlx_get_screen_size(cub->win->mlx, &cub->win->win_x, &cub->win->win_y);
	if (cub->win->win_x < WIDTH || cub->win->win_y < HEIGHT)
		cub_free_before_exit(cub, NO_ERROR);
	cub->win->win = mlx_new_window(cub->win->mlx, WIDTH, HEIGHT, "Cub3d");
	cub->win->img = mlx_new_image(cub->win->mlx, WIDTH, HEIGHT);
}

static void	fs_get_map_size(t_cub *cub)
{
	cub->map->x = ft_strlen(cub->map->map[0]);
	cub->map->y = ft_count_tab_string(cub->map->map);
}

void	cub_init_map(t_cub *cub)
{
	fs_get_map_size(cub);
	cub->win = (t_win *)cub_alloc(cub, 1, sizeof(t_win));
	cub->win->mlx = mlx_init();
	mlx_get_screen_size(cub->win->mlx, &cub->win->win_x,
		&cub->win->win_y);
	if (cub->win->win_x < cub->map->x * GRID
		|| cub->win->win_y < cub->map->y * GRID)
		cub_free_before_exit(cub, ERROR_MAP);
	cub->win->win = mlx_new_window(cub->win->mlx, cub->map->x * GRID, cub->map->y * GRID, "Cub3d	Minimap");
	cub->win->img = mlx_new_image(cub->win->mlx, cub->map->x * GRID, cub->map->y * GRID);
}
