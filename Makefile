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

NAME = resources/players/virtual.filler

SRC = main.c

LIB = libft/libft.a

EXE = 0

ARG = 0
ARG_2 = 0

HEAD = -I Filler.h

OBJET = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	make -C libft/

comp :
	@gcc $(SRC) $(LIB) -o $(NAME)

exe : comp
	@echo "" > res
	@./resources/filler_vm -f resources/maps/map01 -p1 resources/players/virtual.filler -p2 resources/players/abanlin.filler

std_2 : comp
	@echo "" > res
	@./resources/filler_vm -f resources/maps/map01 -p1 resources/players/virtual.filler -p2 resources/players/abanlin.filler | grep "test"


clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)

re : fclean all
