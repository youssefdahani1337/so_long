/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:37:46 by yodahani          #+#    #+#             */
/*   Updated: 2022/12/29 17:37:29 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_c_e(int *ca, t_map *map)
{
	if (ca[0] != 1 && !ft_freemap(&map->m))
		return (ft_error("The map must contain 1 starting position"));
	if (ca[1] != 1 && !ft_freemap(&map->m))
		return (ft_error("The map must contain 1 exit"));
	if (ca[2] <= 0 && !ft_freemap(&map->m))
		return (ft_error("The map must contain at least 1 collectible"));
	map->collect = ca[2];
	return (1);
}

int	ft_freemap(char ***map)
{
	int	i;

	i = 0;
	if (!map || !map[0])
		return (0);
	while (map[0][i])
		free(map[0][i++]);
	free(map[0]);
	map[0] = NULL;
	return (0);
}

t_map	*ft_copymap(t_map map)
{
	t_map	*mapcopy;
	int		i;

	i = 0;
	mapcopy = (t_map *) malloc(sizeof(t_map));
	if (!mapcopy)
		return (NULL);
	*mapcopy = map;
	mapcopy->m = (char **)malloc(sizeof(char *) * (map.rows + 1));
	if (!mapcopy->m)
		return (mapcopy);
	while (i < map.rows)
	{
		mapcopy->m[i] = ft_strdup(map.m[i]);
		if (!mapcopy->m[i])
			return (ft_freemap(&mapcopy->m), free(mapcopy), NULL);
		i++;
	}
	mapcopy->m[map.rows] = NULL;
	return (mapcopy);
}

void	ft_fillflood(t_map *map, int x, int y, char c)
{
	if (map->m[x][y] == '1' || map->m[x][y] == '2' || map->m[x][y] == c)
		return ;
	map->m[x][y] = '2';
	ft_fillflood(map, x - 1, y, c);
	ft_fillflood(map, x + 1, y, c);
	ft_fillflood(map, x, y + 1, c);
	ft_fillflood(map, x, y - 1, c);
}

int	ft_checkacces(t_map map, char c)
{
	t_map		*mapcopy;
	t_position	p;
	int			check;
	char		cc;

	cc = '1';
	if (c == 'P')
		cc = 'E';
	check = 1;
	mapcopy = ft_copymap(map);
	p = ft_findpos(map, c);
	ft_fillflood(mapcopy, p.x, p.y, cc);
	if (ft_findpos(*mapcopy, 'C').x != 0)
		check = 0;
	ft_freemap(&mapcopy->m);
	free(mapcopy);
	return (check);
}
