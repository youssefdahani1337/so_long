/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:13:26 by yodahani          #+#    #+#             */
/*   Updated: 2023/01/06 17:28:43 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_create_map(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	mlx_clear_window(data->mlx, data->window);
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.coulmn)
		{
			ft_putimg(data->map.m[y][x], data,
				IMG_WIDTH * x, IMG_HEIGHT * y);
			x ++;
		}
		y ++;
	}
	ft_printcoll(data);
	ft_progress(data);
	return (1);
}

void	ft_putimg(char c, t_data *data, int posx, int posy)
{
	t_img	img;

	if (ft_strchr("PEC", c))
	{
		img = data->flimg;
		ft_putimgwin(data, img, ft_p(posy, posx));
	}
	if (c == '1')
		img = data->walimg;
	else if (c == 'P')
	{
		img = data->plimg;
		data->player.x = posx / IMG_WIDTH;
		data->player.y = posy / IMG_HEIGHT;
	}
	else if (c == 'C')
		img = data->colimg;
	else if (c == 'E')
		img = data->eximg;
	else
		img = data->flimg;
	ft_putimgwin(data, img, ft_p(posy, posx));
}

t_img	ft_set_img(t_data *data, char *str)
{
	t_img	img;

	img.i = mlx_xpm_file_to_image(data->mlx, str, &img.w, &img.h);
	if (!img.i)
	{
		ft_error("Invalid image path !!");
		ft_destroy(data);
	}
	return (img);
}

void	ft_putimgwin(t_data *data, t_img img, t_position p)
{
	int	x;
	int	y;

	x = p.x + ((IMG_WIDTH - img.w) / 2);
	y = p.y + ((IMG_HEIGHT - img.h) / 2);
	mlx_put_image_to_window(data->mlx, data->window, img.i, x, y);
}
