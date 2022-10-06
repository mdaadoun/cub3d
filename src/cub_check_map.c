#include "../inc/cub.h"

void	fs_set_radiant(t_cub *cub, char c, int y, int x)
{
	cub->player->map_x = x;
	cub->player->map_y = y;
	cub->player->pos_x = (x * GRID) + (GRID / 2);
	cub->player->pos_y = (y * GRID) + (GRID / 2);
	if (c == 'E')
		cub->player->radiant = M_PI;
	if (c == 'N')
		cub->player->radiant = M_PI_2;
	if (c == 'W')
		cub->player->radiant = 3 * M_PI;
	if (c == 'N')
		cub->player->radiant = 3 * M_PI_2;
}

void	fs_check_char_map(t_cub *cub, char **map)
{
	int		count;
	int		i;
	int		tab;
	char	c;

	tab = 0;
	count = 0;
	while (map[tab])
	{
		i = 0;
		while (map[tab][i])
		{
			c = map[tab][i];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				fs_set_radiant(cub, c, tab, i);
				count++;
			}
			i++;
		}
		tab++;
	}
	if (count != 1)
		cub_free_before_exit(cub, ERROR_MAP);
}

void	fs_replace_line(char **map, size_t m_len)
{
	int		tab;
	size_t	len;
	size_t	i;
	char	*tmp;

	tab = 0;
	while (map[tab])
	{
		len = ft_strlen(map[tab]);
		if (len < m_len)
		{
			tmp = ft_calloc(m_len + 1, sizeof(char));
			i = 0;
			while (map[tab][i])
			{
				tmp[i] = map[tab][i];
				i++;
			}
			while (i < m_len)
				tmp[i++] = ' ';
			free(map[tab]);
			map[tab] = tmp;
			tmp = NULL;
		}
		tab++;
	}
}

void	fs_map_space_resize(char **map)
{
	int		tab;
	size_t	len;
	size_t	m_len;

	tab = 0;
	m_len = 0;
	while (map[tab])
	{
		len = ft_strlen(map[tab]);
		if (len > m_len)
			m_len = len;
		tab++;
	}
	fs_replace_line(map, m_len);
}

void	cub_check_map(t_cub *cub)
{
	char	**map;

	map = cub->map->map;
	fs_check_char_map(cub, map);
	fs_map_space_resize(map);
	cub_check_wall_map(cub, map);
}
