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

int         main(void)
{
    char    *line;
    int     fd;

    ft_printf("$$$ exec p1 : [players/virtual.filler]");
    fd = open("42", O_RDWR);
    if (fd >= 0)
        while ((get_next_line(0, &line)))
            ft_fprintf("%s\n", fd, line);
    return (0);
}
