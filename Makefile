# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcorlett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 13:29:31 by rcorlett          #+#    #+#              #
#    Updated: 2024/12/23 13:29:44 by rcorlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror
	
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a	

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME_SERVER): server.c $(LIBFT)
	@$(CC) $(CFLAGS) server.c -o $(NAME_SERVER) -L$(LIBFT_DIR) -lft
	
$(NAME_CLIENT): client.c $(LIBFT)
	@$(CC) $(CFLAGS) client.c -o $(NAME_CLIENT) -L$(LIBFT_DIR) -lft	

clean:
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@make clean -C $(LIBFT_DIR)
	
fclean: clean
	@rm -f $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
