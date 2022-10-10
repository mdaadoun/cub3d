#include "../inc/cub.h"

static bool fs_is_wall(t_cub *cub, t_u16 tx, t_u16 ty)
{
	t_u16 x;
	t_u16 y;

	x = tx / GRID;
	y = ty / GRID;
	if (cub->map->arr[x][y] != '0') // collide to wall
		return (true);
	return (false);
}

static bool	fs_check_colision(t_cub *cub, t_ray ray, t_u16 depth)
{
	t_u16	target_x;
	t_u16	target_y;

	ft_printf("collision ray %d:\n", ray.column_index);
	target_x = (((cub->player->map_x + cub->player->grid_x) - sin(ray.angle)) * depth);
	target_y = (((cub->player->map_x + cub->player->grid_x) + cos(ray.angle)) * depth);
	ft_printf("coordinates target x:%d y:%d\n", target_x, target_y);
	if (fs_is_wall(cub, target_x, target_y))
	{
		ray.length = depth;
		// ray.texture = get texture ? which wall ?
		return (true);
	}
	return (false);
}

void	cub_cast_rays(t_cub *cub)
{
	t_u16	idx;
	t_u16	depth;
	t_ray	*ray;
	t_f32	start_angle;

	start_angle = cub->player->angle - (FOV / 2);
	ray = cub->rays;
	idx = 0;
	depth = 0;
	while (idx != RAYS)
	{
		// ft_printf("depth sonar: ");
		ray[idx].column_index = idx + 1;
		// while(fs_check_colision(cub, ray[idx]))
		// 	depth++;
		while(depth < 10)
		{
			fs_check_colision(cub, ray[idx], depth);
			depth += 1;
		}
		depth = 0;
		ray[idx].angle = start_angle;
		start_angle += STEP;
		idx++;
	}
}