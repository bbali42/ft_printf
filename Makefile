# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbali <bbali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 13:06:27 by bbali             #+#    #+#              #
#    Updated: 2021/12/21 19:12:37 by bbali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

MANDATORY	= 	ft_printf.c \
				convert_u.c \
				convert_hexa.c \
				utils.c

OBJ			= 	$(MANDATORY:.c=.o)
CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re