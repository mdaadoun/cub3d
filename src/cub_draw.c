#include "../inc/cub.h"

static void	fs_get_color(t_color *color, char c)
{
	if (c == '1')
	{
		color->B = 100;
		color->R = 20;
		color->G = 65;
	}
	if (c == '0')
	{
		color->B = 0;
		color->R = 0;
		color->G = 0;
	}
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		color->B = 0;
		color->R = 255;
		color->G = 0;
	}
	color->T = 0;
}

static void	fs_get_rect(t_rect *rect, int x, int y, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		rect->height = 8;
		rect->width = 8;
		rect->x = (x * GRID) + (GRID / 2);
		rect->y = (y * GRID) + (GRID / 2);
	}
	else
	{
		rect->height = 64;
		rect->width = 64;
		rect->x = x * GRID;
		rect->y = y * GRID;
	}
}

static void	fs_draw_map(t_cub *cub, char **map)
{
	t_rect	rect;
	t_color	color;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y] && map[y][x])
	{
		fs_get_color(&color, map[y][x]);
		fs_get_rect(&rect, x, y, map[y][x]);
		if (map[y][x] != ' ')
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
