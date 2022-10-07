#include "../inc/cub.h"


static void	fs_display_vision(t_cub *cub)
{
	t_line	line;
	// t_color	color;

	// color.b = 0;
	// color.r = 255;
	// color.g = 255;
	// color.t = 0;
	line.x1 = (cub->player->map_x + cub->player->grid_x) * GRID;
	line.y1 = (cub->player->map_y + cub->player->grid_y) * GRID;
	line.x2 = (((cub->player->map_x + cub->player->grid_x) - sin(cub->player->angle)) * (GRID));
	line.y2 = (((cub->player->map_y + cub->player->grid_y) + cos(cub->player->angle)) * (GRID));
	// cub_draw_line(cub, &line, &color);
	ft_printf("vision: x1:%d, y1:%d, x2:%d, y2:%d\n", line.x1, line.y1, line.x2, line.y2);
}

int	dg_game_loop(t_cub *cub)
{
	if (cub->world->update)
	{
		cub_draw_world(cub);
		fs_display_vision(cub);
		dg_draw_map(cub, cub->map->arr);
		mlx_put_image_to_window(cub->display->mlx, cub->display->win, cub->display->img, 0, 0);
		cub->world->update = false;
	}
	return (0);
}