# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 13:13:44 by cmunoz-r          #+#    #+#              #
#    Updated: 2019/12/12 14:09:58 by cmunoz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=-@gcc

SRCS=./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c\
	./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_memccpy.c\
	./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c\
	./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c\
	./ft_split.c ./ft_strcat.c ./ft_strchr.c ./ft_strcpy.c ./ft_strdup.c\
	./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c\
	./ft_strncmp.c ./ft_strrchr.c  ./ft_strtrim.c ./ft_substr.c ./ft_strnstr.c\
	./ft_tolower.c ./ft_toupper.c ./get_next_line.c\

B_SRCS= ./ft_lstadd_back_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstclear_bonus.c\
		./ft_lstdelone_bonus.c ./ft_lstiter_bonus.c ./ft_lstlast_bonus.c\
		./ft_lstmap_bonus.c ./ft_lstnew_bonus.c ./ft_lstsize_bonus.c

OBJ=$(SRCS:.c=.o)

B_OBJ=$(B_SRCS:.c=.o)

CFLAGS+=-Werror -Wextra -Wall -I./

$(NAME):	$(OBJ)
		-@$(CC) $(CFLAGS) -c $(SRCS)
		-@ar rc $(NAME) $(OBJ)
		-@ranlib $(NAME)

all: $(NAME)
		
bonus: all $(B_OBJ)
		-@$(CC) $(CFLAGS) -c $(B_SRCS)
		-@ar rc $(NAME) $(B_OBJ)
		-@ranlib $(NAME)

clean:
		-@rm -f $(OBJ) $(B_OBJ)

fclean: clean
		-@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re