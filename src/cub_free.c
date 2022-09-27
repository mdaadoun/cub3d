/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:50 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/27 10:16:49 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"


void	cub_free_split(char **split)
{
	t_i8 i;

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

static void	fs_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
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
			fs_free_map(cub->map);
		if (cub->player)
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
