/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:34:38 by yodahani          #+#    #+#             */
/*   Updated: 2023/01/06 17:34:48 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "../includes/ft_structs.h"
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600

void		ft_init(t_data *data, t_map map);
void		ft_init_img(t_data *data);
t_img		ft_set_img(t_data *data, char *str);
int			ft_check_map(char *str, t_map *map);
int			ft_read_map(char *str, t_map *map);
int			ft_checkext(const char *str, const char *ext);
int			ft_check_c_e(int *ca, t_map *map);
int			ft_check_ca(int x, int y, char c, int *ca);
int			ft_check_rows(char ***map, int *column, int *row);
int			ft_check_wall(t_map *map);
t_map		*ft_copymap(t_map map);
int			ft_checkacces(t_map map, char c);
void		ft_fillflood(t_map *map, int x, int y, char c);
int			ft_create_map(t_data *data);
void		ft_putimg(char c, t_data *data, int posx, int posy);
void		ft_putimgwin(t_data *data, t_img img, t_position p);
int			ft_move(int key, t_data *data);
t_position	ft_findpos(t_map map, char c);
void		ft_win(t_data *data);
int			ft_checkp(t_data *data, t_position p, char c);
t_position	ft_p(int y, int x);
void		ft_replace(t_data *data, t_position p1, t_position p2, int key);
void		ft_echap(int key, t_data *data);
int			ft_up(int key);
int			ft_right(int key);
int			ft_down(int key);
int			ft_left(int key);
int			ft_cross(t_data *data);
void		ft_progress(t_data *data);
int			ft_printwin(void);
int			ft_printbye(void);
void		ft_printcoll(t_data *data);
int			ft_error(char *message);
void		ft_freeme(void **ptr);
int			ft_freemap(char ***map);
void		*ft_destroy(t_data *data);
#endif
