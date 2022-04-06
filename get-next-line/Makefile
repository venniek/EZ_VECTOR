# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/02 13:27:37 by gyeon             #+#    #+#              #
#    Updated: 2022/04/06 15:15:44 by gyeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
TARGET = gnl.a
HEADER = ./
SRC = get_next_line.c \
	get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all : $(TARGET)
$(TARGET) : $(OBJ)
	ar rcs $@ $^
%.o : %.c
	$(GCC) -c $(FLAGS) -I $(HEADER) -o $@ $< 
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(TARGET)
re : clean fclean all
.PHONY : all clean fclean re