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

NAME = virtual

SRC = main.c

LIB = libft/libft.a

EXE = 0

ARG = 0
ARG_2 = 0

OBJET = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : exe

exe :
	@gcc $(SRC) $(LIB) -o $(NAME)
ifneq ($(EXE), 0)
	@./virtual $(EXE)
else
	@echo "Usage : La variable EXE n'est pas initialisee"
endif
clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)

re : fclean all
