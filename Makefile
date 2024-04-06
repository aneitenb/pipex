# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 14:27:00 by aneitenb          #+#    #+#              #
#    Updated: 2024/04/05 16:47:24 by aneitenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_DIR = ./libft

LIBFT = ./libft/libft.a

SOURCES = main.c \
			errors.c \
			utils.c 
			
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

all: $(LIBFT) $(NAME) 

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< 

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(HEADERS) $(LIBFT) -o $(NAME)
	@echo "\033[32;1mCompilation successful!\033[0m"

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJECTS)
	@echo "\033[32;1mCleaned files\033[0m"
	
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "\033[32;1mRemoved program!\033[0m"

re: fclean all

.PHONY: all clean fclean re