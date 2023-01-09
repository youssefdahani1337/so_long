/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmessage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:01:24 by yodahani          #+#    #+#             */
/*   Updated: 2022/12/29 12:07:03 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *message)
{
	int	i;
	int	k;

	k = 0;
	i = ft_strlen(message);
	ft_printf("\033[0;31m");
	ft_printf("____ ____ ____ ____ ____ \n");
	ft_printf("| __\\| . \\| . \\|   || . \\\n");
	ft_printf("|  ]_|  <_|  <_| . ||  <_\n");
	ft_printf("|___/|/\\_/|/\\_/|___/|/\\_/\n");
	ft_printf("  ");
	while (k++ < i)
		ft_printf("-");
	ft_printf("\n| %s |\n", message);
	k = 0;
	ft_printf("  ");
	while (k++ < i)
		ft_printf("-");
	ft_printf("\n");
	ft_printf("\033[0m");
	return (0);
}

int	ft_printwin(void)
{
	ft_printf("\033[0;32m");
	ft_printf("     )   )                    (       )  \n");
	ft_printf("  ( /(( /(          (  (      )\\ ) ( /(  \n");
	ft_printf("  )\\())\\())    (    )\\))(   '(()/( )\\()) \n");
	ft_printf(" ((_)((_)\\     )\\  ((_)()\\ )  /(_)|(_)\\  \n");
	ft_printf("__ ((_)((_) _ ((_) _(())\\_)()(_))  _((_) \n");
	ft_printf("\\ \\ / / _ \\| | | | \\ \\((_)/ /|_ _|| \\| | \n");
	ft_printf(" \\ V / (_) | |_| |  \\ \\/\\/ /  | | | .` | \n");
	ft_printf("  |_| \\___/ \\___/    \\_/\\_/  |___||_|\\_| \n");
	ft_printf("                                         \n");
	printf("\033[0m");
	return (0);
}

int	ft_printbye(void)
{
	ft_printf("\033[0;34m");
	ft_printf("  ____             \n");
	ft_printf(" |  _ \\            \n");
	ft_printf(" | |_) |_   _  ___ \n");
	ft_printf(" |  _ <| | | |/ _ \\\n");
	ft_printf(" | |_) | |_| |  __/\n");
	ft_printf(" |____/ \\__, |\\___|\n");
	ft_printf("         __/ |     \n");
	ft_printf("        |___/      \n");
	printf("\033[0m");
	return (0);
}
