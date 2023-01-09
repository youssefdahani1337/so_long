/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_des.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:25:36 by yodahani          #+#    #+#             */
/*   Updated: 2023/01/06 17:15:09 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *data, t_map map)
{
	data->map = map;
	data->coll = 0;
	data->height = map.rows * IMG_HEIGHT;
	data->width = map.coulmn * IMG_WIDTH;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_error("Something is wrong !!");
		ft_destroy(data);
	}	
	data->window = mlx_new_window(data->mlx, data->width, data->height,
			"So Long");
	if (!data->window)
	{
		ft_error("Something is wrong !!");
		free(data->mlx);
		exit(0);
	}
	data->moves = 0;
	ft_init_img(data);
	ft_create_map(data);
}

void	ft_init_img(t_data *data)
{
	data->o_eximg = ft_set_img(data, "./img/o_exit.xpm");
	data->c_eximg = ft_set_img(data, "./img/exit.xpm");
	data->eximg = data->c_eximg;
	data->flimg = ft_set_img(data, "./img/floor.xpm");
	data->plimgl = ft_set_img(data, "./img/player_left.xpm");
	data->plimgr = ft_set_img(data, "./img/player_right.xpm");
	data->plimg = ft_set_img(data, "./img/player_right.xpm");
	data->walimg = ft_set_img(data, "./img/wall.xpm");
	data->m_coll = ft_set_img(data, "./img/collect_m.xpm");
	data->p_coll = ft_set_img(data, "./img/collect_p.xpm");
	data->colimg = ft_set_img(data, "./img/collect.xpm");
}

void	ft_freeme(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		ptr = NULL;
	}
}

void	*ft_destroy(t_data *data)
{
	if (data->mlx && data->window)
		mlx_destroy_window(data->mlx, data->window);
	ft_freemap(&data->map.m);
	exit(0);
	return (NULL);
}
