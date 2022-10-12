/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:45 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/12 15:14:45 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	cub_free_strarr(char **split)
{
	t_i8	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	fs_free_data(t_data *data)
{
	t_list_str	*list;
	t_list_str	*tmp;

	if (data->filedata)
	{
		list = data->filedata;
		while (list)
		{
			tmp = list;
			list = list->next;
			free(tmp->str);
			free(tmp);
			tmp = NULL;
		}
	}
	free(data->color_c);
	free(data->color_f);
	free(data->imgpath_ea);
	free(data->imgpath_so);
	free(data->imgpath_we);
	free(data->imgpath_no);
	free(data);
}

static void	fs_clear_display(t_display *display)
{
	if (display->mlx)
	{
		if (display->win)
			mlx_destroy_window(display->mlx, display->win);
		if (display->img)
			mlx_destroy_image(display->mlx, display->img);
		mlx_destroy_display(display->mlx);
		free(display->mlx);
	}
	free(display);
}

static void	fs_free_world(t_cub *cub)
{
	if (cub->world)
	{
		free(cub->world->cel_color);
		free(cub->world->flr_color);
		free(cub->world->cel_rect);
		free(cub->world->flr_rect);
		free(cub->world);
	}
}

/*
 * Free memory, print error and exit.
 */
void	cub_free_before_exit(t_cub *cub, t_errkey errkey)
{
	if (cub)
	{
		if (cub->data)
			fs_free_data(cub->data);
		if (cub->img)
			cub_free_img(cub);
		if (cub->display)
			fs_clear_display(cub->display);
		if (cub->map)
		{
			cub_free_strarr(cub->map->arr);
			free(cub->map);
		}
		free(cub->player);
		fs_free_world(cub);
		free(cub);
	}
	if (errkey)
	{
		cub_print_error(errkey, 2);
		exit(EXIT_FAILURE);
	}
	cub_print_error(errkey, 1);
	exit(EXIT_SUCCESS);
}
