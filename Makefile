CC = gcc
CFLAGS = -Werror -Wextra -Wall
RM = rm -f

LIBFT = libft.a
LIBFT_DIR = libft

NAME = minirt

INC = -I./incs

SRCS = $(wildcard ./srcs/*.c)

%.o: %.c
	$(CC) -I. -I$(LIBFT_DIR) -c $< -o $@

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	$(CC) $(CFLAGS) $(OBJS) -L. -lft -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
