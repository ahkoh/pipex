# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 14:08:45 by skoh              #+#    #+#              #
#    Updated: 2021/09/08 20:47:38 by skoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
headers	= libft.h
sources	:= $(wildcard *_*.c)
objects	:= $(sources:.c=.o)
ARFLAGS = -rsv
CFLAGS	= -Wall -Werror -Wextra

.PHONY	: all bonus clean fclean re

all	bonus $(NAME): $(NAME)($(objects))

clean	:
	$(RM) $(objects)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

$(objects): $(headers)

norm	: $(headers) $(sources)
	@norminette $^ | (! grep -E '(^\t|Error|Warning)') && echo $@ OK
