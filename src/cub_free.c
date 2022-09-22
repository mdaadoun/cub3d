/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:50 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/22 14:54:14 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	fs_free_data(t_data *data)
{
	t_list_str	*list;
	t_list_str	*tmp;

	if (!data->data_list)
		return ;
	list = data->data_list;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->str);
		free(tmp);
		tmp = NULL;
	}
}

static void	fs_clear_window(t_win *win)
{
	if (win)
	{
		mlx_destroy_window(win->mlx, win->win);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		free(win);
	}
}

void	cub_free_before_exit(t_cub *cub, t_errkey errkey)
{
	if (cub)
	{
		fs_free_data(cub->data);
		free(cub->data);
		fs_clear_window(cub->win);
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
