# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/02 13:27:37 by gyeon             #+#    #+#              #
#    Updated: 2021/10/02 14:28:28 by gyeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
TARGET = gnl.a
HEADER_BONUS = ./
SRC_BONUS = get_next_line_bonus.c \
	get_next_line_utils_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(TARGET)
$(TARGET) : $(OBJ_BONUS)
	ar rcs $@ $^
%.o : %.c
	$(GCC) -c $(FLAGS) -I $(HEADER_BONUS) -o $@ $< 
clean :
	@rm -rf $(OBJ_BONUS)
fclean :
	@rm -rf $(TARGET)
re : clean fclean all
.PHONY : all clean fclean re