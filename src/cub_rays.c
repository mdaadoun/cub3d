#include "../inc/cub.h"

// get the texture on the wall from the ray and the position on the wall
// static bool	fs_get_texture()
// {

// }

static bool fs_is_wall(t_cub *cub, t_ray ray)
{
	t_u16 x;
	t_u16 y;

	x = ray.target_x / GRID;
	y = ray.target_y / GRID;
	if (cub->map->arr[y][x] == '1')
		return (true);
	return (false);
}

static bool	fs_check_colision(t_cub *cub, t_ray ray)
{
	ray.target_x = (((cub->player->map_x + cub->player->grid_x) * GRID) - (sin(ray.angle) * ray.length));
	ray.target_y = (((cub->player->map_y + cub->player->grid_y) * GRID) + (cos(ray.angle) * ray.length));
	if (fs_is_wall(cub, ray))
	{
		// fs_get_texture(ray);
		return (true);
	}
	return (false);
}

void	cub_cast_rays(t_cub *cub)
{
	t_u16	idx;
	t_ray	*ray;
	t_f32	start_angle;

	start_angle = cub->player->angle - (FOV / 2);
	ray = cub->rays;
	idx = 0;
	while (idx != RAYS)
	{
		ray[idx].angle = start_angle;
		ray[idx].length = 1;
		ray[idx].column_index = idx + 1;
		while(!fs_check_colision(cub, ray[idx]))
			ray[idx].length += 1;
		idx++;
		start_angle += STEP;
	}
}