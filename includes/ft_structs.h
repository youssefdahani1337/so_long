/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:58:13 by yodahani          #+#    #+#             */
/*   Updated: 2023/01/02 17:23:28 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# define IMG_HEIGHT 40
# define IMG_WIDTH 40
# define COLLECT_WIDTH 20

typedef struct s_position{
	int	x;
	int	y;
}	t_position;

typedef struct s_map{
	int		coulmn;
	int		rows;
	int		collect;
	char	**m;
}	t_map;

typedef struct s_img{
	void	*i;
	int		w;
	int		h;
}	t_img;

typedef struct s_data{
	void		*mlx;
	void		*window;
	t_map		map;
	t_position	player;
	int			width;
	int			height;
	int			coll;
	int			moves;
	t_img		o_eximg;
	t_img		c_eximg;
	t_img		eximg;
	t_img		walimg;
	t_img		colimg;
	t_img		plimg;
	t_img		plimgr;
	t_img		plimgl;
	t_img		flimg;
	t_img		m_coll;
	t_img		p_coll;
}	t_data;

#endif