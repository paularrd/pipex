# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 11:57:23 by fle-tolg          #+#    #+#              #
#    Updated: 2022/12/07 11:24:53 by fle-tolg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
END = \033[0m

NAME = pipex

NAME_B = pipex_bonus

CFLAGS = -Wextra -Wall -Werror

LIBFT = ./libft/libft.a

LIBFT_DIR = ./libft/ --no-print-directory

CC = clang -g

RM = rm -f

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

SRC = 	mandatory/sources/main.c\
		mandatory/sources/initalize_pipex.c\
		mandatory/sources/ft_error.c\
		mandatory/sources/get_func.c

SRC_BONUS =	bonus/sources/main.c\
			bonus/sources/initalize_pipex.c\
			bonus/sources/ft_pipex_utils.c\
			bonus/sources/get_func.c\
			bonus/sources/read_heredoc.c

all : $(NAME) $(LIBFT)

bonus : $(NAME_B) $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : ${OBJ}
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "${GREEN}$(NAME) compilated with success"

$(NAME_B) : ${OBJ_BONUS}
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_B)
	@echo "${GREEN}$(NAME) with bonus compilated with success"

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@echo "$(NAME) clean"

fclean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJ) $(OBJ_BONUS) $(NAME) pipex_bonus
	@echo "${RED}$(NAME) fclean"

norme :
	norminette libft
	norminette mandatory
	norminette bonus

re :	fclean all

.PHONY :
	all bonus clean fclean norme re
