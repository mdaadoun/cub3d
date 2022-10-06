#include "../inc/cub.h"

static void	fs_move_player_left(t_cub *cub, char **map, int x, int y)
{
	cub->player->pos_x -= STEP;
	if (cub->player->pos_x < 0)
	{
		if (map[y][x - 1] == '1')
		{
			cub->player->pos_x += STEP;
			return ;
		}
		cub->player->pos_x = 1.0;
		cub->player->map_x -= 1;
	}
}

static void	fs_move_player_right(t_cub *cub, char **map, int x, int y)
{
	cub->player->pos_x += STEP;
	if (cub->player->pos_x > 1)
	{
		if (map[y][x + 1] == '1')
		{
			cub->player->pos_x -= STEP;
			return ;
		}
		cub->player->pos_x = 0.0;
		cub->player->map_x += 1;
	}
}

static void	fs_move_player_top(t_cub *cub, char **map, int x, int y)
{		
	cub->player->pos_y -= STEP;
	if (cub->player->pos_y < 0)
	{
		if (map[y - 1][x] == '1')
		{
			cub->player->pos_y += STEP;
			return ;
		}
		cub->player->pos_y = 1.0;
		cub->player->map_y -= 1;
	}
}

static void	fs_move_player_down(t_cub *cub, char **map, int x, int y)
{
	cub->player->pos_y += STEP;
	if (cub->player->pos_y > 1)
	{
		if (map[y + 1][x] == '1')
		{
			cub->player->pos_y -= STEP;
			return ;
		}
		cub->player->pos_y = 0.0;
		cub->player->map_y += 1;
	}
}

void	cub_move_player(t_cub *cub, t_u16 key)
{
	char	**map;
	int		x;
	int		y;

	map = cub->map->map;
	x = cub->player->map_x;
	y = cub->player->map_y;
	cub->world->update = true;
	if (key == XK_a)
		fs_move_player_left(cub, map, x, y);
	if (key == XK_d)
		fs_move_player_right(cub, map, x, y);
	if (key == XK_w)
		fs_move_player_top(cub, map, x, y);
	if (key == XK_s)
		fs_move_player_down(cub, map, x, y);
}
