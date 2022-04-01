CC = gcc
CFLAGS = -Werror -Wextra -Wall
RM = rm -f

LIBFT = libft.a
LIBFT_DIR = libft
GNL = gnl.a
GNL_DIR = get-next-line

NAME = minirt

INC = -I./incs

SRCS = $(wildcard ./srcs/*.c)

%.o: %.c
	$(CC) -I. -I $(LIBFT_DIR) $(GNL_DIR) -c $< -o $@ -g

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	$(MAKE) -C $(GNL_DIR)
	cp $(GNL_DIR)/$(GNL) .
	$(CC) $(CFLAGS) $(OBJS) -L. -lft $(GNL) -o $@ -g

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
