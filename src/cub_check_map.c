#include "../inc/cub.h"

void	cub_check_char_map(t_cub *cub, char **map)
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
				cub_init_player(cub, c, tab, i);
				count++;
			}
			i++;
		}
		tab++;
	}
	if (count != 1)
		cub_free_before_exit(cub, ERROR_MAP);
}

static void	fs_replace_line(char **map, size_t m_len)
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
		}
		tab++;
	}
}

void	cub_map_space_resize(char **map)
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

static bool	fs_check_cub(char **map, int y, int x, char c)
{
	char	*line;

	if (x == 0 || y == 0 || y == (int)ft_count_tab_string(map) - 1)
		return (true);
	line = map[y - 1];
	if (line[x - 1] == c || line[x] == c || line[x + 1] == c)
		return (true);
	line = map[y];
	if (line[x - 1] == c || line[x + 1] == c)
		return (true);
	line = map[y + 1];
	if (line[x - 1] == c || line[x] == c || line[x + 1] == c)
		return (true);
	return (false);
}

void	cub_check_wall_map(t_cub *cub, char **map)
{
	int		tab;
	int		i;
	char	c;

	tab = 0;
	while (map[tab])
	{
		i = 0;
		while (map[tab][i])
		{
			c = map[tab][i];
			if (c == '0' || c == 'N' || c == 'S'
				|| c == 'E' || c == 'W')
				if (fs_check_cub(map, tab, i, ' ')
					|| fs_check_cub(map, tab, i, '\0'))
					cub_free_before_exit(cub, ERROR_MAP);
			i++;
		}
		tab++;
	}
}
