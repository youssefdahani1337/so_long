/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:56:57 by yodahani          #+#    #+#             */
/*   Updated: 2022/12/20 19:24:59 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include<unistd.h>
# include<stdio.h>

char	*ft_substring_nl(char **str);
char	*ft_strjoin_nl(char **str, char *s);
void	ft_fill(char *dst, char *src, int start, size_t len);
int		ft_nl(char *s);
char	*ft_free(char **str, char *s);
char	*ft_end(char **str, char *s);
char	*ft_read(int fd, char **str);
char	*get_next_line(int fd);
#endif