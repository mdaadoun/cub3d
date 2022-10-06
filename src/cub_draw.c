#include "../inc/cub.h"

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

static void	fs_get_rect(t_cub *cub, int x, int y, char c)
{
	t_rect	*rect;

	rect = &cub->rect;
	if (cub_is_player(c))
	{
		rect->height = 8;
		rect->width = 8;
		rect->x = (cub->player->map_x + cub->player->pos_x) * 64;
		rect->y = (cub->player->map_y + cub->player->pos_y) * 64;
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
	int		x;
	int		y;

	x = 0;
	y = 0;
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

static void	fs_draw_player(t_cub *cub)
{
	ft_printf("Draw player!\n");
	(void) cub;
}

static void	fs_draw_vision(t_cub *cub)
{
	t_line	line;
	t_color	color;

	color.b = 0;
	color.r = 150;
	color.g = 0;
	color.t = 0;
	line.x1 = (cub->player->map_x + cub->player->pos_x) * GRID;
	line.y1 = (cub->player->map_y + cub->player->pos_y) * GRID;
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
