#include "../inc/cub.h"

static void	fs_get_color(t_color *color, char c)
{
	if (c == '1')
	{
		color->B = 150;
		color->R = 20;
		color->G = 65;
	}
	if (c == '0')
	{
		color->B = 200;
		color->R = 200;
		color->G = 200;
	}
	if (cub_is_player(c))
	{
		color->B = 0;
		color->R = 150;
		color->G = 0;
	}
	color->T = 0;
}

static void	fs_get_rect(t_rect *rect, int x, int y, char c)
{
	if (cub_is_player(c))
	{
		rect->height = 8;
		rect->width = 8;
		rect->x = (x * GRID) + (GRID / 2);
		rect->y = (y * GRID) + (GRID / 2);
	}
	else
	{
		rect->height = GRID;
		rect->width = GRID;
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
		if (cub_is_player(map[y][x]))
		{
			fs_get_color(&color, '0');
			fs_get_rect(&rect, x, y, '0');
			cub_draw_rectangle(cub, &rect, &color);
		}
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

static void	fs_draw_vision(t_cub *cub)
{
	t_line line;
	t_color	color;

	color.B = 0;
	color.R = 150;
	color.G = 0;
	color.T = 0;
	line.x1 = cub->player->map_x * GRID;
	line.y1 = cub->player->map_y * GRID;
	line.x2 = 64;
	line.y2 = 64;
	cub_draw_line(cub, &line, &color);

}

void	cub_draw_world(t_cub *cub)
{
	cub_draw_rectangle(cub, cub->world->cel_rect, cub->world->cel_color);
	cub_draw_rectangle(cub, cub->world->flr_rect, cub->world->flr_color);
	fs_draw_map(cub, cub->map->map);
	fs_draw_vision(cub);
	fs_draw_player(cub);
}
