/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pgcd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:57:52 by brvalcas          #+#    #+#             */
/*   Updated: 2018/11/05 15:40:28 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

int		main(int argc, char **argv)
{
	int x;
	int y;

	if (argc != 3)
	{
		ft_printf("Usage : ./pgcd [x] [y]\n");
		return (0);
	}
	x = ft_atoi(argv[argc - 2]);
	y = ft_atoi(argv[argc - 1]);
	ft_printf("Le PGCD de %d et %d est = [%d]\n", x, y, pgcd(x, y));
	return (0);
}
