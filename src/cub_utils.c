#include "../inc/cub.h"

void	*cub_alloc(t_cub *cub, size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(nmemb, size);
	if (!ptr)
		cub_free_before_exit(cub, ERROR_MALLOC);
	return (ptr);
}

bool	cub_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

void	cub_init_player(t_cub *cub, char c, int y, int x)
{
	cub->player->map_x = x;
	cub->player->map_y = y;
	cub->player->grid_x = ((GRID / 2.0) / GRID);
	cub->player->grid_y = ((GRID / 2.0) / GRID);
	cub->player->fov = M_PI / 3;
	if (c == 'N')
		cub->player->angle = M_PI;
	else if (c == 'E')
		cub->player->angle = 3 * M_PI_2;
	else if (c == 'W')
		cub->player->angle = M_PI_2;
	else if (c == 'S')
		cub->player->angle = 0;
}
