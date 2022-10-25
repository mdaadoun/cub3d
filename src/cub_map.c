/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:51 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/25 14:14:48 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static bool	fs_check_line(char *line)
{
	int		i;
	char	c;

	if (!line)
		return (true);
	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c != '0' && c != '1' && c != 'N' && c != 'S'
			&& c != 'E' && c != 'W' && c != ' ')
			break ;
		i++;
	}
	if (line[i] == '\n' || line[i] == '\0')
		return (true);
	return (false);
}

static size_t	fs_check_all_line(t_cub *cub, t_list_str *data)
{
	size_t	len;

	len = 0;
	while (data)
	{
		if (fs_check_line(data->str) == false)
			cub_free_before_exit(cub, ERROR_MAP);
		len++;
		data = data->next;
	}
	return (len);
}

void	cub_build_map(t_cub *cub, t_list_str *data_list)
{
	char	**map;
	size_t	nb_lines;
	int		i;

	while (data_list->str)
	{
		if (ft_strlen(data_list->str) >= 1 && data_list->str[0] == '\n')
			data_list = data_list->next;
		else
			break ;
	}
	nb_lines = fs_check_all_line(cub, data_list);
	map = cub_alloc(cub, nb_lines, sizeof(char *));
	i = 0;
	while (data_list)
	{
		map[i] = ft_strtrim(data_list->str, "\n");
		data_list = data_list->next;
		i++;
	}
	cub->map->arr = map;
}

void	cub_check_map(t_cub *cub)
{
	char	**map;

	map = cub->map->arr;
	cub_check_char_map(cub, map);
	cub_map_space_resize(cub, map);
	cub_check_wall_map(cub, map);
}

bool	cub_player_can_go(t_cub *cub, t_f32	x, t_f32 y)
{
	int	test_x;
	int	test_y;

	test_x = (int)(x + cub->player->map_x);
	test_y = (int)(y + cub->player->map_y);
	if (cub->map->arr[test_y][test_x] != '1')
		return (true);
	return (false);
}
