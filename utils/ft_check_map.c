/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:01:10 by yodahani          #+#    #+#             */
/*   Updated: 2023/01/06 17:28:38 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(char *str, t_map *map)
{
	if (!ft_checkext(str, ".ber"))
		return (ft_error("The map's extention must end by .ber"));
	if (!ft_read_map(str, map))
		return (0);
	if (!ft_check_wall(map))
		return (0);
	if (!ft_checkacces(*map, 'P'))
		return (ft_error("inaccessible Collectible !!"));
	if (!ft_checkacces(*map, 'E'))
		return (ft_error("inaccessible Exit !!"));
	return (1);
}

int	ft_read_map(char *str, t_map *map)
{
	int		fd;
	char	*l;
	char	*m;

	m = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_error("Invalid Map File"));
	l = get_next_line(fd);
	if (!l || l[0] == 0)
		return (ft_error("empty file"));
	while (l)
	{
		if (l[0] == '\n')
			return (ft_free(&m, l), ft_error("Invalid rows lenght"));
		m = ft_strjoin_nl(&m, l);
		if (!m)
			return (ft_free(&m, l), ft_error("Can't join strings !!"));
		free(l);
		l = get_next_line(fd);
	}
	if (m && m[ft_strlen(m) -1] == '\n')
		return (ft_free(&m, 0), ft_error("The map's end is not valid"));
	map->m = ft_split(m, '\n');
	return (free(m), ft_check_rows(&map->m, &map->coulmn, &map->rows));
}

int	ft_check_rows(char ***map, int *column, int *row)
{
	size_t	len;

	*column = 0;
	*row = 0;
	if (!map || !map[0] || !map[0][0])
		return (ft_error("something is wrong !!"));
	len = ft_strlen(map[0][0]);
	while (map[0][*row])
	{
		if (ft_strlen(map[0][*row]) != len)
		{
			ft_freemap(map);
			return (ft_error("The lenght of the columns must be equal!"));
		}
		(*row)++;
	}
	*column = ft_strlen(map[0][0]);
	if (*column == *row)
	{
		ft_freemap(map);
		return (ft_error("The map must be rectangular."));
	}
	return (1);
}

int	ft_check_ca(int x, int y, char c, int *ca)
{
	if ((x == 0 || y == 0 || x == ca[3] - 1) && c != '1')
		return (ft_error("The map must be closed/surrounded by walls"));
	else if (c == 'P' && ca[0]++ > 0)
		return (ft_error("The map must contain 1 starting position"));
	else if (c == 'E' && ca[1]++ > 0)
		return (ft_error("The map must contain 1 exit!"));
	else if (c == 'C')
		ca[2]++;
	else if (!ft_strchr("01ECPA", c))
		return (ft_error("invalid charcatter(s)"));
	return (1);
}

int	ft_check_wall(t_map *map)
{
	int	x;
	int	y;
	int	ca[4];

	ca[0] = 0;
	ca[1] = 0;
	ca[2] = 0;
	ca[3] = map->rows;
	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->coulmn)
		{
			if (!ft_check_ca(x, y, map->m[x][y], ca))
				return (ft_freemap(&map->m));
			y ++;
		}
		if (map->m[x][y - 1] != '1')
			return (ft_freemap(&map->m),
				ft_error("The map must be closed/surrounded by walls"));
		x ++;
	}
	return (ft_check_c_e(ca, map));
}
