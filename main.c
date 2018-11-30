/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:25:13 by brvalcas          #+#    #+#             */
/*   Updated: 2018/11/30 22:25:14 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/ft_printf.h"

int         main(int ac, char **av)
{
    char    *line;
    int     fd;
    int     x;
    int     y;

    y = 0;
    if (ac == 2)
    {
        fd = open(av[ac - 1], O_RDONLY);
        if (fd >= 0)
            while ((get_next_line(fd, &line)))
            {
                ft_printf("%s|x = %d|y = %d\n", line, ft_strlen(line), ++y);
                free(line);
            }
        else
            ft_printf("Bad argument\n");
    }
    
    else
        ft_printf("Usage : ./player [map]\n");
    return (0);
}
