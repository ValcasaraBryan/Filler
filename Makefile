# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 23:28:47 by brvalcas          #+#    #+#              #
#    Updated: 2018/11/30 23:28:47 by brvalcas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brvalcas.filler

SRC =	srcs/main.c\
		srcs/mappage.c\
		srcs/before_mappage.c\
		srcs/map_chaleur.c\
		srcs/utils.c\
		srcs/allocation.c\
		srcs/check_chaleur.c\
		srcs/check_pos_map.c\
		srcs/init_val.c\
		srcs/liberation.c\
		srcs/parsing_map.c\
		srcs/parsing_piece.c\
		srcs/genere_list.c\
		srcs/norm_main.c\
		srcs/norm_init_val.c

LIB = libft/libft.a


OBJET = $(SRC:.c=.o)

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)
CC = gcc

all : $(NAME)

$(OBJET):$(INCLUDES)

$(NAME) : $(OBJET)
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) $(OBJET) -o $@

exe :
	make && mv brvalcas.filler resources/players/ && ./resources/filler_vm -f resources/maps/map01 -p1 "valgrind --leak-check=full ./resources/players/brvalcas.filler" -p2 resources/players/abanlin.filler > 42

clean :
	@rm -f $(OBJET)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft

re : fclean all
