#include "../inc/cub.h"

static void fs_draw_map(t_cub *cub, char **map)
{
	t_rect	rect;
	t_color	color;
	int 	x;
	int		y;

	rect.height = 64;
	rect.width = 64;
	color.B = 100;
	color.R = 20;
	color.G = 65;
	color.T = 0;
	x = 0;
	y = 0;
	while (map[y] && map[y][x])
	{
		// get_color(&color, map[y][x], map[y]);
		rect.x = x * 64;
		rect.y = y * 64;
		if (map[y][x] == '1')
			cub_draw_rectangle(cub, &rect, &color);
		x++;
		if (!map[y][x])
		{
			x = 0;
			y++;
		}
	}
	cub->world->update = true;
}

static void	fs_draw_player(t_cub *cub)
{
	ft_printf("Draw player!\n");
	(void) cub;
}

void	cub_draw_world(t_cub *cub)
{
	cub_draw_rectangle(cub, cub->world->cel_rect, cub->world->cel_color);
	cub_draw_rectangle(cub, cub->world->flr_rect, cub->world->flr_color);
	fs_draw_map(cub, cub->map->map);
	fs_draw_player(cub);
}
