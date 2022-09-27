/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:25:42 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/27 16:28:33 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	fs_set_color(t_i8 index, t_color *color, t_i8 col)
{
	if (index == 0)
		color->R = col;
	else if (index == 1)
		color->G = col;
	else if (index == 2)
		color->B = col;
}

bool	cub_check_set_colors(t_cub *cub, t_color *color, char *colstr)
{
	char	**colors;
	t_u16	i;
	t_i16	col;

	colors = ft_split(colstr, ',');
	i = 0;
	while (colors[i])
	{
		col = ft_atoi(colors[i]);
		if (col < 0 || col > 255)
			cub_free_before_exit(cub, ERROR_FORMAT);
		fs_set_color(i, color, col);
		i++;
	}
	if (i != 3)
		cub_free_before_exit(cub, ERROR_FORMAT);
	cub_free_strarr(colors);
	return (true);
}
