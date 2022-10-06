#include "../inc/cub.h"

void	cub_rotate_player(t_cub *cub, t_u16 key)
{
	ft_printf("rotate %d\n", key);
	(void) cub;
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
	if (key == XK_d)
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
	if (key == XK_w)
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
	if (key == XK_s)
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
}
