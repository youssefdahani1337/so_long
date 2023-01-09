/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addons.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:02:14 by yodahani          #+#    #+#             */
/*   Updated: 2023/01/02 18:03:49 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkext(const char *str, const char *ext)
{
	int	lenstr;
	int	lenext;
	int	i;

	i = 0;
	lenstr = ft_strlen(str) - 1;
	lenext = ft_strlen(ext) - 1;
	while (lenext >= 0 && lenstr >= 0)
	{
		if (str[lenstr--] != ext[lenext--])
			return (0);
	}
	return (1);
}

t_position	ft_findpos(t_map map, char c)
{
	int			i;
	int			j;
	t_position	p;

	i = 0;
	p.x = 0;
	p.y = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.coulmn)
		{
			if (c == map.m[i][j])
			{
				p.x = i;
				p.y = j;
				return (p);
			}
			j++;
		}
		i++;
	}
	return (p);
}

void	ft_echap(int key, t_data *data)
{
	if (key == 53)
	{
		ft_printbye();
		ft_destroy(data);
	}
}

void	ft_printcoll(t_data *data)
{
	char		*str;
	int			i;
	long		color;
	int			w;

	w = data->width - 100;
	color = 16688255;
	i = 0;
	str = ft_itoa(data->moves);
	str = ft_strjoin_nl(&str, " Steps");
	mlx_string_put(data->mlx, data->window, w, 10, color, str);
	free(str);
}

int	ft_cross(t_data *data)
{
	ft_printbye();
	ft_destroy(data);
	return (1);
}
