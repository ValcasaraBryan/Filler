# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 10:41:12 by roliveir          #+#    #+#              #
#    Updated: 2018/12/14 21:00:18 by roliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
SRCS = ft_bzero.c ft_memcpy.c ft_memset.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_is_prime.c ft_find_next_prime.c ft_atoi_base.c ft_putnbr_base.c ft_print_words_tables.c ft_convert_base.c ft_del_words_tables.c get_next_line.c ft_strjoinf.c ft_print_digit_tables.c ft_print_digit.c ft_strclen.c
PRINTF = ft_printf/ft_caster.c ft_printf/ft_conv_base.c ft_printf/ft_flag.c ft_printf/ft_flag2.c ft_printf/ft_float.c ft_printf/ft_iscase.c ft_printf/ft_manager.c ft_printf/ft_nbrtoa.c ft_printf/ft_print.c ft_printf/ft_search.c ft_printf/ft_putchar_p.c ft_printf/ft_putstr_p.c ft_printf/printf.c
INCLUDES = libft.h
OBJ = $(SRCS:.c=.o)
PFOBJ = $(PRINTF:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	@$(CC) -g -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ) $(PFOBJ)
	@ar rc $(NAME) $(OBJ) $(PFOBJ)
	@ranlib $(NAME)

noprintf : $(OBJ) libft.h
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
clean:
	@/bin/rm -f $(OBJ) $(PFOBJ)
	@/bin/rm -f $(PFOBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
.PHONY: clean fclean all re noprintf
