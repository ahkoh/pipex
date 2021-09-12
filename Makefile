# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 14:25:35 by skoh              #+#    #+#              #
#    Updated: 2021/09/12 14:11:08 by Koh              ###   ########.kl        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
libft	= libft/libft.a
makelib	= make -C libft
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address -g3

all bonus: $(NAME)

$(NAME): $(libft) src/pipex*.c
	$(CC) $(CFLAGS) src/pipex*.c $(libft) -o $(NAME)

$(libft): force
	$(makelib) bonus

clean:
	rm -rf *.o
	$(makelib) $@

fclean: clean
	rm -rf $(NAME)
	$(makelib) $@

re: fclean all

.PHONY: all bonus clean fclean re force
