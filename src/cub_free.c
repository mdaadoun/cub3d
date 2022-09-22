/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:50 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/22 09:47:04 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	fs_free_data(t_data *data)
{
	t_list_str	*list;
	t_list_str	*tmp;

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

void	fs_clear_window(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
}

void	cub_free_before_exit(t_cub *cub, t_errkey errkey)
{
	//fs_free_data(&cub->data);
	fs_clear_window(&cub->win);
	(void) cub;
	if (errkey)
	{
		cub_print_error(errkey, 2);
		exit(EXIT_FAILURE);
	}
	cub_print_error(errkey, 1);
	exit(EXIT_SUCCESS);
}
