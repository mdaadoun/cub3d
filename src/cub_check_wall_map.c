#include "../inc/cub.h"

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
