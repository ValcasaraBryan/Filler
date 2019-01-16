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
		srcs/norm_main.c

LIB = libft/libft.a

LIB_FILLER = Filler.a

OBJET = $(SRC:.c=.o)

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)
CC = gcc

all : $(NAME)

$(OBJET):$(INCLUDES)

$(NAME) : $(OBJET)
	@make -C libft
	@ar rc $(LIB_FILLER) $^
	@ranlib $(LIB_FILLER)
	@$(CC) $(CFLAGS) $(LIB) $(LIB_FILLER) -o $@

exe :
	make && mv brvalcas.filler resources/players/ && cat coucou | ./resources/players/brvalcas.filler

exe_norm :
	make && mv brvalcas.filler resources/players/ && ./resources/filler_vm -f resources/maps/map01 -p1 "valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./resources/players/brvalcas.filler" -p2 resources/players/abanlin.filler > 42

norm :
	norminette **/*[.c.h]

clean :
	@rm -f $(OBJET)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@rm -f $(LIB_FILLER)
	@make fclean -C libft

re : fclean all
