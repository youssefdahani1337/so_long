/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:35:19 by yodahani          #+#    #+#             */
/*   Updated: 2023/01/06 17:07:29 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **argv)
{
	t_data	data;
	t_map	map;

	if (ac < 2)
		return (ft_error("enter the Path of the map"));
	if (ac > 2)
		return (ft_error("enter just the Path of the map"));
	if (!ft_check_map(argv[1], &map))
		return (0);
	ft_init(&data, map);
	mlx_hook(data.window, 2, 0, ft_move, &data);
	mlx_hook(data.window, 17, 0, ft_cross, &data);
	mlx_loop(data.mlx);
	return (0);
}
