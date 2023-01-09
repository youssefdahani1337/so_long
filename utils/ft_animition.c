/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:13:13 by yodahani          #+#    #+#             */
/*   Updated: 2023/01/02 18:37:01 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_progress(t_data *data)
{
	int	i;
	int	posx;
	int	posy;
	int	j;

	j = 0;
	i = 0;
	posy = 15;
	while (i < data->coll)
	{
		posx = 20 * i + 5;
		mlx_put_image_to_window(data->mlx, data->window,
			data->p_coll.i, posx, posy);
		i++;
	}
	while (j < data->map.collect)
	{
		posx = 20 * i + 5;
		mlx_put_image_to_window(data->mlx, data->window,
			data->m_coll.i, posx, posy);
		i++;
		j++;
	}
}
