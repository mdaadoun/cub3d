/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:23:04 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/27 10:50:52 by dlaidet          ###   ########.fr       */
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
	map = ft_calloc(nb_lines, sizeof(char *));
	i = 0;
	while (data_list)
	{
		map[i] = ft_strtrim(data_list->str, "\n");
		data_list = data_list->next;
		i++;
	}
	cub->map = map;
}
