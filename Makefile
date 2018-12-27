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
		srcs/genere_list.c\
		srcs/utils.c\
		srcs/allocation.c\
		srcs/check_chaleur.c\
		srcs/check_pos_map.c\
		srcs/init_val.c\
		srcs/liberation.c\
		srcs/parsing_map.c\
		srcs/parsing_piece.c\

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

clean :
	@rm -f $(OBJET)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@rm -f $(LIB_FILLER)
	@make fclean -C libft

re : fclean all
