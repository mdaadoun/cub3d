/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:47 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/12 15:14:48 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	*fs_open_img(t_cub *cub, char *path)
{
	void	*ptr;
	int		wid;
	int		hei;

	ptr = mlx_xpm_file_to_image(cub->display->mlx, path, &wid, &hei);
	if (!ptr)
		cub_free_before_exit(cub, ERROR_IMG);
	return (ptr);
}

t_buffer	*fs_load_buf(t_cub *cub, void *img)
{
	t_buffer	*buf;

	buf = (t_buffer *)cub_alloc(cub, sizeof(t_buffer), 1);
	buf->buffer = mlx_get_data_addr(img, \
			&buf->pixel_bits, &buf->line_bytes, &buf->endian);
	return (buf);
}

void	cub_load_img(t_cub *cub)
{
	if (cub->data->imgpath_no)
	{
		cub->img->no = fs_open_img(cub, cub->data->imgpath_no);
		cub->img->no_buf = fs_load_buf(cub, cub->img->no);
	}
	if (cub->data->imgpath_so)
	{
		cub->img->so = fs_open_img(cub, cub->data->imgpath_so);
		cub->img->so_buf = fs_load_buf(cub, cub->img->so);
	}
	if (cub->data->imgpath_ea)
	{
		cub->img->ea = fs_open_img(cub, cub->data->imgpath_ea);
		cub->img->ea_buf = fs_load_buf(cub, cub->img->ea);
	}
	if (cub->data->imgpath_we)
	{
		cub->img->we = fs_open_img(cub, cub->data->imgpath_we);
		cub->img->we_buf = fs_load_buf(cub, cub->img->we);
	}
}

void	cub_free_img(t_cub *cub)
{
	if (cub->img->no)
	{
		mlx_destroy_image(cub->display->mlx, cub->img->no);
		free(cub->img->no_buf);
	}
	if (cub->img->so)
	{
		mlx_destroy_image(cub->display->mlx, cub->img->so);
		free(cub->img->so_buf);
	}
	if (cub->img->ea)
	{
		mlx_destroy_image(cub->display->mlx, cub->img->ea);
		free(cub->img->ea_buf);
	}
	if (cub->img->we)
	{
		mlx_destroy_image(cub->display->mlx, cub->img->we);
		free(cub->img->we_buf);
	}
	free(cub->img);
	cub->img = 0;
}
