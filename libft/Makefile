# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 11:57:23 by fle-tolg          #+#    #+#              #
#    Updated: 2022/12/06 14:30:44 by fle-tolg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
END=\033[0m

NAME = libft.a

CFLAGS = -Wextra -Wall -Werror

CC = clang -g

AR = ar rcs

RM = rm -f

OBJ = $(SRC:.c=.o)

SRC =	ft_isprint.c\
	ft_putchar_fd.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_atoi.c\
	ft_itoa.c\
	ft_putendl_fd.c\
	ft_strlcat.c \
	ft_substr.c\
	ft_bzero.c\
	ft_putnbr_fd.c\
	ft_strlcpy.c\
	ft_tolower.c\
	ft_calloc.c\
	ft_memchr.c\
	ft_putstr_fd.c\
	ft_strlen.c\
	ft_toupper.c\
	ft_isalnum.c\
	ft_memcmp.c\
	ft_split.c\
	ft_split_utils.c\
	ft_strmapi.c\
	ft_isalpha.c\
	ft_memcpy.c\
	ft_strchr.c\
	ft_strncmp.c\
	ft_strcmp.c\
	ft_isascii.c\
	ft_memmove.c\
	ft_strdup.c\
	ft_strnstr.c\
	ft_isdigit.c\
	ft_memset.c\
	ft_striteri.c\
	ft_strrchr.c\
	ft_strchr_char.c\
	ft_lstnew.c\
	ft_lstadd_back.c\
	ft_lstsize.c\
	ft_lstadd_front.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstmap.c\
	db_lstnew.c\
	db_lstadd_back.c\
	db_lstsize.c\
	db_lstadd_front.c\
	db_lstdelone.c\
	db_lstclear.c\
	db_lstlast.c\
	db_lstfirst.c\
	ft_putnbr_base_fd.c\
	ft_printf.c\
	ft_printf_utils.c\
	ft_fprintf.c\
	ft_fprintf_utils.c\
	get_next_line.c\
	get_next_line_zero.c

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : ${OBJ}
	@$(AR) $(NAME) $(OBJ)
	@echo "${GREEN}Libft.a created"

all : $(NAME)

clean :
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@echo "${RED}Libft clean"

fclean :
	@$(RM) $(NAME) $(OBJ) $(OBJ_BONUS)
	@echo "${RED}Libft fclean"

norme :
	norminette

re :	fclean all

.PHONY :
	all clean fclean re
