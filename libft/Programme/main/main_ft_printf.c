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

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_printf("resultat : [");
        ft_printf("]\nretour   : [%d]\n", ft_printf("%s", argv[argc - 1]));
    }
    else
        ft_printf("Usage : ./ft_printf [string]");
    return (0);
}
