#include "../inc/cub.h"

// free rays

void	cub_cast_rays(t_cub *cub)
{
	t_u16	i;
	t_ray	*ray;
	t_f32	start_angle;

	start_angle = cub->player->angle - (FOV / 2);
	ray = cub->rays;
	i = 0;
	while (i != WIDTH)
	{
		ray[i].column_index = i + 1;
		ray[i].angle = start_angle;
		start_angle += STEP;
		i++;
	}
}