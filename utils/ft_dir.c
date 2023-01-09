/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:40:12 by yodahani          #+#    #+#             */
/*   Updated: 2023/01/05 09:28:21 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_up(int key)
{
	return (key == 126 || key == 13);
}

int	ft_right(int key)
{
	return (key == 124 || key == 2);
}

int	ft_down(int key)
{
	return (key == 125 || key == 1);
}

int	ft_left(int key)
{
	return (key == 123 || key == 0);
}
