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

t_piece     *new(char *content, int x, int y, char c, char v)
{
    t_piece *data;

    if (!(data = malloc(sizeof(t_piece))))
        return (NULL);
    if (!content)
        return (NULL);
    data->piece = content;
    data->x = x;
    data->y = y;
    data->me = c;
    data->vs = v;
    data->next = NULL;
    return (data);
}

t_piece     *add(t_piece *last, t_piece *new)
{
    t_piece *tmp;

    if (!new)
        return (last);
    else if (!last)
        return (new);
    else
    {
        tmp = last;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        return (last);
    }
}

static char    *parsing_filler(char *line)
{
    int i;
    char *tmp;

    i = 0;
    if (ft_isdigit(line[i]))
        i += 4;
    if (line[i])
    {
        tmp = ft_strdup(line + i);
        free(line);
        line = NULL;
        return (tmp);
    }
    else
        return (NULL);
}

int         main(int argc, char **argv)
{
    t_piece *data;
    t_piece *head;
    char    *line;
    static int     player = 0;
    int     versus;
    char    c;
    char    v;
    int     y;
    int     x;
    int fd;

    y = 0;
    fd = open("res", O_RDWR);
    if (player == 0 && get_next_line(0, &line))
    {
        player = (!(ft_strstr(line, argv[0]))) ? 2 : 1;
        free(line);
//        ft_printf("$$$ exec p%d : [%s]\n", player, argv[0]);
    }
    c = (player == 1) ? 'O' : 'X';
    v = (player == 1) ? 'X' : 'O';
    while ((get_next_line(0, &line)))
    {
        if (!ft_strstr(line, "Plateau") && !ft_strstr(line, "Piece") && !ft_strstr(line, "0123456789"))
        {
            line = parsing_filler(line);
            data = add(data, new(line, ft_strlen(line), ++y, c, v));
        }
    }
    head = data;
    y = 0;
    x = 0;
    while (head)
    {
        if ((y = ft_strnchr(head->piece, c, head->y)) > -1)
        {
            ft_fprintf("%d %d\n", 2, x, y);
            ft_printf("%d %d\n", x, y);
            break;
        }
        head = head->next;
        x++;
    }
    close(fd);
    return (0);
}
