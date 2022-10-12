/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:06 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/12 15:54:52 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (c == 'N')
		cub->player->angle = M_PI;
	else if (c == 'E')
		cub->player->angle = 3 * M_PI_2;
	else if (c == 'W')
		cub->player->angle = M_PI_2;
	else if (c == 'S')
		cub->player->angle = 0;
}

char	*cub_get_pixel(t_buffer *bs, t_u16 x, t_u16 y)
{
	int	pixel;

	pixel = (y * bs->line_bytes) + (x * 4);
	return (&bs->buffer[pixel]);
}

void	*cub_get_texture(t_cub *cub, t_texture id)
{
	if (id == TEXTURE_EAST)
		return (cub->img->ea_buf);
	if (id == TEXTURE_WEST)
		return (cub->img->we_buf);
	if (id == TEXTURE_NORTH)
		return (cub->img->no_buf);
	if (id == TEXTURE_SOUTH)
		return (cub->img->so_buf);
	return (0);
}
