/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:44:31 by brvalcas          #+#    #+#             */
/*   Updated: 2018/11/27 16:44:50 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"
#include "../../includes/get_next_line.h"


int         main(int argc, char **argv)
{
    char    *line;
    int ret;
    int fd;

    if (argc != 2)
        return (0);
    ret = 0;
    fd = open(argv[1], O_RDWR);   
    while ((ret = get_next_line(0, &line)) > 0)
    {
        ft_printf("len = %d | retour = %d\n", ft_printf("%s\n", line), ret);
        free(line);
    }
    ft_printf("len = %d | retour = %d\n", ft_printf("%s\n", line), ret);
    close(fd);
    return (0);
}