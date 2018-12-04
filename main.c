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

#include "Filler.h"

int         main(int argc, char **argv)
{
    char    *line;
    static int     player = 0;
    char    me;

    if (player == 0 && get_next_line(0, &line))
    {
        player = (!(ft_strstr(line, argv[0]))) ? 2 : 1;
        free(line);
        ft_printf("$$$ exec p%d : [%s]\n", player, argv[0]);
    }
    me = (player == 1) ? 'O' : 'X';
    return (0);
}
