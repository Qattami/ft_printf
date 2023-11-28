# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iqattami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 10:14:00 by iqattami          #+#    #+#              #
#    Updated: 2023/11/24 10:14:54 by iqattami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prinft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -f $(OBJ) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
