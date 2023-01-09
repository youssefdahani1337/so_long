/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:25:35 by yodahani          #+#    #+#             */
/*   Updated: 2023/01/05 09:31:15 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int key, t_data *data)
{
	t_position	pos;
	t_position	p;

	p = ft_p(data->player.y, data->player.x);
	pos = ft_p(0, 0);
	ft_echap(key, data);
	if (ft_up(key))
		pos = ft_p(p.y - 1, p.x);
	else if (ft_right(key))
		pos = ft_p(p.y, p.x + 1);
	else if (ft_down(key))
		pos = ft_p(p.y + 1, p.x);
	else if (ft_left(key))
		pos = ft_p(p.y, p.x - 1);
	if (!ft_checkp(data, pos, '1') && !ft_checkp(data, pos, 'E'))
		ft_replace(data, p, pos, key);
	else if (ft_checkp(data, pos, 'E'))
		ft_win(data);
	if (!ft_checkp(data, pos, '1') && data->moves != 0)
		ft_printf("\033[0;32m [%d] steps \033[0m\n", data->moves);
	return (1);
}

void	ft_replace(t_data *data, t_position p1, t_position p2, int key)
{
	if (data->map.m[p2.y][p2.x] == 'C')
	{
		data->coll++;
		data->map.collect--;
	}
	data->map.m[p1.y][p1.x] = '0';
	data->map.m[p2.y][p2.x] = 'P';
	data->moves++;
	if (data->map.collect == 0)
		data->eximg = data->o_eximg;
	if (ft_left(key))
		data->plimg = data->plimgl;
	else if (ft_right(key))
		data->plimg = data->plimgr;
	ft_create_map(data);
}

void	ft_win(t_data *data)
{
	if (data->map.collect == 0)
	{
		ft_printwin();
		ft_destroy(data);
	}
}

t_position	ft_p(int y, int x)
{
	t_position	p;

	p.x = x;
	p.y = y;
	return (p);
}

int	ft_checkp(t_data *data, t_position p, char c)
{
	if (data->map.m[p.y][p.x] == c)
		return (1);
	return (0);
}
