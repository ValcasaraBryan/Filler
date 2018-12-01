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

OBJET = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	make -C libft/

exe :
	@gcc $(SRC) $(LIB) -o $(NAME)
	@./resources/filler_vm -f resources/maps/map00 -p1 resources/players/virtual.filler -p2 resources/players/abanlin.filler

std_2 :
	@gcc $(SRC) $(LIB) -o $(NAME)
	@./resources/filler_vm -f resources/maps/map00 -p1 resources/players/virtual.filler -p2 resources/players/abanlin.filler | grep "std 2"

clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)

re : fclean all
