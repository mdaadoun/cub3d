/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:50 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/28 09:36:03 by dlaidet          ###   ########.fr       */
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

static void	fs_clear_window(t_win *win)
{
	if (win->mlx)
	{
		mlx_destroy_window(win->mlx, win->win);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	free(win);
}

static void	fs_clear_map(t_map *map)
{
	if (map->map)
		cub_free_strarr(map->map);
	free(map);
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
		if (cub->win)
			fs_clear_window(cub->win);
		if (cub->map)
			fs_clear_map(cub->map);
		free(cub->world->cel_color);
		free(cub->world->flr_color);
		free(cub->world);
		free(cub->player);
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
